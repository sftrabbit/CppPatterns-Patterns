// Sleep on current thread

#include <chrono>
#include <thread>

int main()
{
	std::chrono::milliseconds sleepDuration(20);

	std::this_thread::sleep_for(sleepDuration);
}

// 
// [`sleep_for`](cpp/thread/sleep_for) will block the execution of the 
// current thread for _at least_ the 
// specified duration. The time unit may be `milliseconds`, `seconds` or
// the other types defined in [`std::chrono::duration`](cpp/chrono/duration)

