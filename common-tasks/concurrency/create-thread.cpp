// Create a thread
// C++11

#include <thread>
#include <string>
#include <functional>

void func(std::string str, int& x);
void do_something();

int main()
{
  std::string str = "Test";
  int x = 5;

  std::thread t{func, str, std::ref(x)};

  do_something();

  t.join();
}

// Execute code on a separate thread.
//
// On [16], we create a [`std::thread`](cpp/thread/thread) object `t`,
// which represents a thread of execution. When constructing `t`, we
// pass `func` as the function to execute on that thread.
//
// To pass arguments to `func`, we have passed them as additional
// arguments to `std::thread`'s constructor. Notice that to pass an
// argument by reference, it must be wrapped in a
// [`std::reference_wrapper`](cpp/utility/functional/reference_wrapper)
// &mdash; to do this, we use the [`std::ref`](cpp/utility/functional/ref)
// helper function. For `const` references, use
// [`std::cref`](cpp/utility/functional/cref).
//
// After creating the thread, the remainder of `main` continues to
// execute as normal. At the same time, function `func` begins
// executing in the newly-created thread. This means that the bodies
// of `func` and `main` will be executing concurrently. They may be
// executed in parallel if the system supports parallel execution.
//
// On [20] we call `t`'s [`join`](cpp/thread/thread/join) member
// function. This causes `main`'s thread to block until the thread
// finishes execution (which is when `func` returns). Once `join`
// returns, execution continues in `main`'s thread.
//
// **Note**: A thread must be either joined or detached before
// destruction, or [`std::terminate`](cpp/error/terminate) will be
// called.
//
// **Note**: If `func` propagates an exception, `std::terminate` will
// be called.

void func(std::string, int&)
{ }

void do_something()
{ }
