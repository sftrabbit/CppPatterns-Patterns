// Sleep

#include <chrono>
#include <thread>

int main()
{
	std::chrono::milliseconds sleepDuration(20);

	std::this_thread::sleep_for(sleepDuration);
}

// Block the execution of a thread for a given amount of time.
// 
// On [8], we create a [`std::chrono::milliseconds`](cpp/chrono/duration)
// object representing the number of milliseconds to sleep (other
// duration units may also be used). On [10], the call to
// [`std::this_thread::sleep_for`](cpp/thread/sleep_for) will block
// the execution of the current thread for at least the given
// duration.

