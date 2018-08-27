// Fixed time step
// C++11, C++14

#include <chrono>
#include <thread>

using namespace std::literals::chrono_literals;

void some_complex_work();

int main()
{
  using clock = std::chrono::steady_clock;
  clock::time_point next_time_point = clock::now() + 5s;

  some_complex_work();

  std::this_thread::sleep_until(next_time_point);
}

// Block the execution of a thread until a fixed point in time.
//
// For the purposes of demonstrating this pattern, we use
// [`std::chrono::steady_clock`](cpp/chrono/steady_clock) ([13]),
// although any other clock will suffice.
//
// On [14], we create a `clock::time_point` representing the point in
// time five seconds from now. To do so, we use `clock::now()` to get
// the current time point and add the duration of `5s` to it. Here we
// have used one of C++14's [duration literal
// suffixes](http://en.cppreference.com/w/cpp/chrono/duration#Literals)
// to representing a duration with the seconds suffix, `s`. The
// `using` directive on [7] is required in order to use these suffixes.
// For C++11, the duration can be constructed manually.
//
// After performing some complex work on [16], we then call
// [`std::this_thread::sleep_until`](cpp/thread/sleep_until) on [18],
// passing it the time point we computed earlier. This blocks the
// current thread until we have reached that time point, ensuring that
// execution continues exactly five seconds after the starting time,
// regardless of how much time the complex work took (unless it took
// more than five seconds).
//
// This technique is most commonly used in a loop to ensure that the
// loop iterates with a fixed time step. Alternatively, if you want to
// sleep for a fixed amount of time, see the [sleep
// sample](/patterns/sleep.html).

void some_complex_work() { }
