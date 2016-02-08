// Concurrent tasks
// C++11

#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <utility>

int func(int a, int b)
{
	// Delay a bit
	std::this_thread::sleep_for(std::chrono::seconds{3});
	
	// Uncomment the following line to try an error
	//throw std::runtime_error{"error calculating answer"};
	
	return a * b;
}

int main()
{
	std::future<int> answer = std::async(func, 6, 7);
	// Or, if we want to request that func is executed concurrently:
	//std::future<int> answer = std::async(std::launch:async, func, 6, 7);
	
	try
	{
		auto ans = answer.get();
		std::cout << "The answer is " << ans << '\n';
	}
	catch (std::exception const& x)
	{
		std::cerr << x.what() << '\n';
	}
}

// Execute a task concurrently.
// 
// While we could use `std::thread` and `std::promise` (or perhaps
// `std::thread` and `std::packaged_task`) to cobble together a way to
// run tasks concurrently, [`std::async`](cpp/thread/async) is a
// higher-level way to accomplish this.
// 
// On [23] we call `std::async` with `func` as the first argument, and
// the arguments we want passed to `func` as the remaining arguments.
// (Note that all arguments will be passed to `func` by value, which
// means copying or moving. If we wanted to use any reference
// arguments, we would have to use `std::ref` or `std::cref`.) We
// capture the result as a future.
// 
// By default, `std::async` will decide whether to execute the task
// concurrently, or to wait until we request the result and then
// execute the task non-concurrently at that time. If we want to
// specifically request one of those behaviours we can use a flag as
// the first argument. To request concurrent execution (if possible),
// we would use `std::launch::async`. To request that the task is
// executed only when we need the result (non-concurrently), we
// would use `std::launch::deferred`.
// 
// When we need the result on [29], we use the `get()` member function.
// This blocks until the result is available, unless the task throws
// an exception (in which case, the exception is rethrown in the
// current thread).
// 
// (Note that it is important that we capture the future returned by
// `std::async`. If we do not, then the call will always block.)
