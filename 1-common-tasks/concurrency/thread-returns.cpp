// Thread return values
// C++11

#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <thread>
#include <utility>

void func(std::promise<int> answer_promise) noexcept
{
	try
	{
		// Delay a bit
		std::this_thread::sleep_for(std::chrono::seconds{3});
		
		// Uncomment the following line to try an error
		//throw std::runtime_error{"error calculating answer"};
		
		answer_promise.set_value(42);
	}
	catch (...)
	{
		answer_promise.set_exception(std::current_exception());
	}
}

int main()
{
	std::promise<int> answer_promise = {};
	std::future<int> answer_future = answer_promise.get_future();
	
	std::thread t{func, std::move(answer_promise)};
	
	// ...
	
	try
	{
		auto answer = answer_future.get();
		std::cout << "The answer is " << answer << '\n';
	}
	catch (std::exception const& x)
	{
		std::cerr << x.what() << '\n';
	}
	
	t.join();
}

// Return values from a thread.
// 
// We could use reference arguments to return values from a thread
// function, but futures are a better option. (Better still would be
// using `async`.)
// 
// On [31] we create a [`std::promise`](cpp/thread/promise), and on
// [32] we get a future from that promise before passing it (by
// moving, because promises cannot be copied) to a thread.
// 
// In the thread function on [21], we set that promise to the return
// value. Alternately, if there was an error, we could set the
// promise's exception to indicate that.
// 
// On [40], we use the future's `get()` function to try to get the
// promised return value. This function will block until there is a
// value or an exception available. If there is a value, it is simply
// returned. Alternately, if there was an exception stored, it is
// thrown.
