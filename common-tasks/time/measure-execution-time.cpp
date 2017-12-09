// Measure execution time

#include <chrono>

int main()
{
  using clock = std::chrono::steady_clock;

  clock::time_point start = clock::now();
  // A long task...
  clock::time_point end = clock::now();

  clock::duration execution_time = end - start;
}

// Measure the execution time of a unit of code.
//
// We introduce the type alias `clock` on [7] such that it refers to
// the [`std::chrono::steady_clock`](cpp/chrono/steady_clock) type.
// This type represents a monotonic (always increasing) clock.
//
// Before and after the task that we wish to time ([9] and [11]
// respectively), we call the static member function `clock::now`
// which gives us a
// [`std::chrono::time_point`](cpp/chrono/time_point) representing the
// point in time at which it was called. By subtracting the `start`
// time point from the `end` time point on [13], we get a
// [`std::chrono::duration`](cpp/chrono/duration) representing the
// time taken between these time points and, therefore, the execution
// time of our task.
//
// We can access the value of a `std::chrono::duration` by calling its
// `count` member function. The units of the `std::chrono::duration`
// are determined by the clock it came from, but it can be casted to
// another `std::duration` with different units with the
// [`std::chrono::duration_cast`](chrono/duration/duration_cast)
// function (or implicitly, if the units are exactly divisible).
