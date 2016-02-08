// Create a thread
// C++11

#include <thread>

void func()
{
	// body
}

int main()
{
	std::thread t{func};
	
	// ...
	
	t.join();
}

// Create a thread.
// 
// On [9], we create a [`std::thread`](cpp/thread/thread) object `t`,
// which represents an operating system thread (whatever that may mean
// for the operating system it is running on).
// 
// A default-constructed `std::thread` object is empty - it does
// nothing useful. So when constructing `t`, we pass a reference to
// function `func`.
// 
// After creating the thread, the constructor returns immediately, and
// the remainder of `main` continues to execute in the original
// thread. At the same time (more or less, depending on system
// scheduling), function `func` begins executing in the newly-created
// thread. This means that, in theory, the body of `func` ([8]) and
// the code in `main` ([14-16]) will be executing at the same time, in
// parallel. (In reality, there are situations where this might not
// happen, such as if the system does not support parallel execution.)
// 
// A thread that is not empty (that is, one that is not created with
// the default `std::thread` constructor, or moved-from) must be
// either detached or joined before destruction, or
// [`std::terminate()`](cpp/error/terminate) will be called. Joining
// is more common (detaching is dangerous), so on [17] we call `t`'s
// [`join()`](cpp/thread/thread/join) function. This causes the
// original thread (the one `main` is running in) to block until `t`'s
// thread function (which is `func`) returns. (`func` must not let an
// exception propagate out of its body, or `std::terminate` will be
// called.)
// 
// Once `join()` returns, `t` is empty - the thread it represented is
// gone - and control continues once more in the original thread.
