// Thread arguments
// C++11

#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <thread>

void func(long y, std::string n, int& answer, std::string const& q)
{
	// Let's not actually wait 7.5 million years...
	std::chrono::seconds calculation_time{3};
	std::this_thread::sleep_for(calculation_time);
	
	answer += 42;
}

int main()
{
	long years = 7500000;
	std::string name = {"Deep Thought"};
	std::string const question = {"What is the answer?"};
	int answer = 0;
	
	std::thread t{func, years, name, std::ref(answer), std::cref(question)};
	
	std::cout << "Calculating the answer, please wait..." << std::endl;
	
	t.join();
	
	std::cout << "The answer is " << answer << '\n';
}

// Pass arguments to a thread function.
// 
// On [22], we create a [`std::thread`](cpp/thread/thread) object `t`.
// In the constructor call, we pass `func` as the first argument - this
// is the thread function. The remaining constructor arguments are
// passed to `func`.
// 
// Arguments that are passed by value require no extra work - they are
// simply copied (or moved) before the thread constructor returns.
// 
// Arguments that are passed by reference must be passed using
// [`std::ref`](cpp/utility/functional/ref). Arguments passed by
// `const` reference must be passed using
// [`std::cref`](cpp/utility/functional/cref).
// 
// On [28], after the thread has completed, we can observe that the
// value of `answer` has been changed (it was changed on [12], which
// was executed in the other thread). This is a limited way of getting
// a "return value" from a thread, but there are better ways.
// 
// (Note that while it is generally not recommended to use
// `std::endl`, it is necessary to use it on [28]. This is because we
// want to ensure the "please wait" message is flushed *immediately*
// to the output - *before* `t.join()` blocks - rather than being
// buffered and potentially not being displayed until after the delay
// we wish to ask the user to wait through.)
