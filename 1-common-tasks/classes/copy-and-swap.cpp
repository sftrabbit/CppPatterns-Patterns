// Copy-and-swap
// C++11

#include <utility>

class resource {
	int x = 0;
};

class foo
{
	public:
		foo()
			: p{new resource{}}
		{ }

		foo(const foo& other)
			: p{new resource{*(other.p)}}
		{ }

		foo(foo&& other)
			: p{other.p}
		{
			other.p = nullptr;
		}

		foo& operator=(foo other)
		{
			swap(*this, other);

			return *this;
		}

		~foo()
		{
			delete p;
		}

		friend void swap(foo& first, foo& second)
		{
			using std::swap;

			swap(first.p, second.p);
		}

	private:
		resource* p;
};

// Implement the assignment operator with strong exception safety.
// 
// The copy-and-swap idiom identifies that we can implement a
// classes copy/move assignment operators in terms of its
// copy/move constructor and achieve strong exception safety.
// 
// The class `foo`, on [10-48], has an implementation similar to the
// [rule of five](/common-tasks/rule-of-five.html), yet its copy and
// move assignment operators have been replaced with a single
// assignment operator on [27-32]. This assignment operator takes its
// argument by value, making use of the existing copy and move
// constructor implementations.
// 
// To implement the assignment operator, we simply need to swap the
// contents of `*this` and the argument, `other`. When `other` goes
// out of scope at the end of the function, it will destroy any
// resources that were originally associated with the current object.
// 
// To achieve this, we define a `swap` function for our class on
// [39-44], which itself calls `swap` on the class's members ([43]).
// We use a using-declaration on [41] to allow `swap` to be found
// via [argument-dependent lookup](http://en.wikipedia.org/wiki/Argument-dependent_name_lookup)
// before using `std::swap` &mdash; this is not strictly necessary
// in our case, because we are only swapping a pointer, but is good
// practice in general. Our assignment operator then simply swaps
// `*this` with `other` on [29].
// 
// The copy-and-swap idiom has inherent strong exception safety
// because all allocations (if any) occur when copying into the
// `other` argument, before any changes have been made to `*this`.
// It is generally, however, less optimized than a more custom
// implementation of the assignment operators.
// 
// **Note**: We can typically avoid manual memory management and
// having to write the copy/move constructors, assignment operators,
// and destructor entirely by using the
// [rule of zero](/common-tasks/rule-of-zero.html)

int main()
{
	foo f1, f2, f3;
	f2 = f1;
	f3 = std::move(f1);

	swap(f2, f3);
}
