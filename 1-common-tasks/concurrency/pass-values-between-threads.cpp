// Pass values between threads
// C++11

#include <future>
#include <thread>

void func(std::promise<int> result_promise) noexcept
{
	result_promise.set_value(42);
}

int main()
{
	std::promise<int> result_promise;
	std::future<int> result_future = result_promise.get_future();
	
	std::thread t{func, std::move(result_promise)};
	
	int result = result_future.get();
	
	t.join();
}

// Use promises to communicate values between threads.
// 
// On [14] we create a [`std::promise`](cpp/thread/promise), which
// provides a mechanism for passing objects asynchronously between
// threads. On [15] we get a [`std::future<int>`](cpp/thread/future)
// from that promise, representing an `int` value that will arrive at
// some point in the future. We then move the promise into a new
// thread (as promises cannot be copied).
// 
// On [9], in the thread function, we set the value of the promise to
// the value that we wish to asynchronously communicate back to
// `main`. 
//
// On [19], we call the future's `get` function to try to get the
// promised return value. This function will block until there is a
// value (or an exception) available. When the value is available
// (that is, when the value of the promise has been set on [9]), it
// will be returned by `get`.
