// Concurrent queue
// C++11

#include <algorithm>
#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <sstream>
#include <string>
#include <thread>

template <typename T>
class concurrent_queue
{
public:
	void push(T t)
	{
		std::unique_lock<std::mutex> lock{mutex_};
		queue_.push(std::move(t));
		lock.unlock();
		cond_.notify_one();
	}
	
	T pop()
	{
		std::unique_lock<std::mutex> lock{mutex_};
		cond_.wait(lock, [this]{ return !queue_.empty(); });
		T temp = std::move(queue_.front());
		queue_.pop();
		return temp;
	}
	
private:
	std::mutex mutex_;
	std::condition_variable cond_;
	std::queue<T> queue_;
};

int const num_producers = 4;
int const num_iterations = 5;

void produce(concurrent_queue<std::string>& q)
{
	std::string s = []{
		std::ostringstream oss;
		oss << "thread " << std::this_thread::get_id();
		return oss.str();
	}();
	
	for (int i = 0; i < num_iterations; ++i)
	{
		q.push(s);
		std::this_thread::sleep_for(std::chrono::milliseconds{100});
	}
}

int main()
{
	concurrent_queue<std::string> q;
	
	std::vector<std::thread> producers(num_producers);
	std::generate(std::begin(producers), std::end(producers),
		[&q]{ return std::thread{produce, std::ref(q)}; });
	
	for (int i = 0; i < num_producers * num_iterations; ++i)
		std::cout << q.pop() << '\n';
	
	std::for_each(std::begin(producers), std::end(producers),
		[](std::thread& t) { t.join(); });
}

// Implement a basic concurrent queue.
// 
// [!15-40] illustrate a basic concurrent queue - a queue designed for
// sharing a data stream between multiple threads.
// 
// The heart of the queue is a [`std::queue`](cpp/container/queue)
// ([39]). To synchronize access to the queue, we need a
// [`std::mutex`](cpp/thread/mutex) ([37]). A
// [`std::condition_variable`](cpp/thread/condition_variable) ([38])
// will help us send messages efficiently across threads.
// 
// In the push function on [19-25], we first attempt to acquire a lock
// on the queue's mutex ([21]). This is is necessary, because we don't
// want to try making any changes to `queue_` - or even attempting to
// read it - while another thread might be in the process of changing
// it. Once we have acquired the lock, we know we are the sole owners
// of the queue object, so it is safe to make changes to it. So on
// [22] we push the argument onto the end of the queue, then on [23]
// we immediately relinquish the lock - we never want to hold a lock
// any longer than we have to. After that, we send a notification to
// one waiting thread (assuming there is any) to alert them that there
// is an item in the queue.
// 
// In the pop function on [27-34], we begin again by acquiring the
// lock ([29]). Then on [30], we ask the condition variable to wait
// until the queue is not empty. The way this works is that the
// condition variable first checks the test in the lambda, and if
// that is false (if the queue *is* empty), it releases the lock and
// then blocks until it is notified. When it receives a notification,
// it reacquires the lock and checks the test again (because sometimes
// there are phenomena called "spurious wakeups"). Once again, if the
// test fails, the condition variable releases the lock and returns to
// waiting. But if the test is true - in this case, if the queue is
// not empty, wait returns (while keeping the lock on the mutex). So
// when we get to [31], we know two things: we have acquired a lock on
// `mutex_`, and `queue_` is not empty. Therefore we can safely move
// from the object at the front of the queue ([31]), then remove it
// from the queue ([32]), and return it ([33]). The lock is
// automatically released when the function returns.
// 
// Because this is a very basic concurrent queue, there are a few
// things to be cautious about.
// 
// This first thing to be cautious about is that the total number of
// items pushed to the queue *must* be greater than or equal to the
// number of pop attempts. If there is a pop attempt, and no other
// threads are pushing items to the queue, that pop attempt will cause
// a deadlock - it will forever wait for another item to be pushed to
// the queue, even though no more are coming.
// 
// This problem can be fixed, but it requires either tolerating that
// `pop()` might throw an exception when there will be no more items
// coming, or redesigning the interface of `pop()`. Perhaps `pop()`
// could return `std::optional<T>`, and the caller is required to
// check the result.
// 
// The second thing to be cautious about: objects on the queue may be
// lost forever in the pop function if their move assignment operator
// can throw exceptions. To understand why, imagine we are on line
// [32]. At this point, we have successfully moved the object at the
// front of the queue into `temp` (which destroys the original in the
// queue), and removed it from the queue entirely (on [33]). Now the
// return statement tries to move from `temp` into the result object
// in the caller... and then there's an exception. Even if you manage
// to catch the exception in the caller, `temp` is lost. The original
// object on the queue is also lost. So whatever that data was, it's
// not gone, and cannot be recovered.
// 
// In reality, this problem is not as serious as it sounds. First, it
// is generally good practice, for many reasons - and it is usually
// possible to do - to make move operations non-throwing.
// `std::string`, which we used in the example, has non-throwing move
// ops. Second, because the function, as it is written, can leverage
// named return value optimization, the `temp` variable will usually
// be optimized away, so when the object is moved out of the front of
// the queue it will be moved *directly* into the return value in the
// caller. If that fails, then as long as the move assignment
// operation has the strong exception guarantee, there will be no
// problem - the move attempt will be rolled back as if it had never
// been attempted at all. So the only *dangerous* types will be types
// that a) have a throwing move assignment operator that b) offers
// only the weak exception guarantee or worse. Types *that* twitchy
// probably shouldn't be put in a concurrent queue in the first place.
// In fact, types that have throwing move ops don't have to be
// tolerated at all - if someone really wants to put them in a
// concurrent queue, they can be wrapped in smart pointers. So perhaps
// the best way to deal with this problem is to use a
// `static_assert` to enforce
// `std::is_nothrow_move_assignable<T>::value`.
