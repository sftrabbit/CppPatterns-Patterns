// Sleep
// C++11, C++14

#include <chrono>
#include <thread>

using namespace std::literals::chrono_literals;

int main()
{
	std::chrono::milliseconds sleepDuration(20);
	std::this_thread::sleep_for(sleepDuration);

	std::this_thread::sleep_for(5s);
}

// Block the execution of a thread for a given amount of time.
// 
// On [10], we create a [`std::chrono::milliseconds`](cpp/chrono/duration)
// object representing the number of milliseconds to sleep (other
// duration units may also be used). On [11], the call to
// [`std::this_thread::sleep_for`](cpp/thread/sleep_for) will block
// the execution of the current thread for at least the given
// duration.
//
// On [13], we demonstrate the use of C++14's [duration literal
// suffixes](http://en.cppreference.com/w/cpp/chrono/duration#Literals)
// by representing a duration with the seconds suffix, `s`. The
// `using` directive on [7] is required in order to use these suffixes.

