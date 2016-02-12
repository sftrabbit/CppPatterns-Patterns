// Execute a task asynchronously
// C++11

#include <future>

int func()
{
	int some_value = 0;

	// Do work...

	return some_value;
}

int main()
{
	std::future<int> result_future = std::async(func);

	// Do something...
	
	int result = result_future.get();
}

// High-level asynchronous execution of tasks.
// 
// [`std::async`](cpp/thread/async) provides a high-level way to
// accomplish asynchronous execution of tasks, abstracting over
// [`std::thread`](cpp/thread/thread) and
// [`std::promise`](cpp/thread/promise).
// 
// On [17], we call `std::async`, passing `func` as the function to
// execute asynchronously. Arguments to `func` can be passed as
// additional arguments to `std::async`. The return value is a
// [`std::future<int>`](cpp/thread/future), representing an `int`
// value that will be returned from the task at some point in the
// future.
// 
// By default, `std::async` will decide whether to execute the task
// concurrently or to wait until we request the result and then
// execute the task. If we want to specifically request one of these
// behaviours, we can use a flag as the first argument. To request
// concurrent execution, if possible, we use
// [`std::launch::async`](cpp/thread/launch). To request that the task
// is executed only when the result is needed, we use
// [`std::launch::deferred`](cpp/thread/launch).
// 
// On [21], we use the `std::future`'s `get` member function to get
// the result of the asynchronous task. This blocks until the result
// is available.
// 
// **Note**: It is important that we capture the future returned by
// `std::async`. If we do not, then the call will always block.
