// The rule of three

#include <utility>

class foo
{
	public:
		foo()
			: p{new int{5}}
		{ }

		foo(const foo& other)
			: p{new int{*(other.p)}}
		{ }

		foo& operator=(foo other)
		{
			std::swap(p, other.p);
			return *this;
		}

		~foo()
		{
			delete p;
		}

	private:
		int* p;
};

// Implement RAII to encapsulate and safely manage dynamically
// allocated resources.
// 
// The class `foo` dynamically allocates an `int` object in its
// constructor ([9]). To ensure that the lifetime of this `int` is
// tied to the lifetime of the `foo` object that allocated it, 
// we deallocate it in `foo`'s destructor ([24]). This idiom, known as
// [RAII](http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization),
// ensures that dynamically allocated objects are properly destroyed
// and no memory is leaked, even if an exception occurs.
// 
// We also implement a copy constructor ([12-14]) and an assignment
// operator ([16-20]) to manage this resource when copying or
// assigning a `foo`. In general, if a class has a destructor, it
// almost certainly needs these functions too. This idea is known
// as the *rule of three*.
// 
// Note that we can typically avoid manual memory management and
// having to write the copy constructor, assignment operator, and
// destructor entirely by using the
// [rule of zero](/common-tasks/rule-of-zero.html)

int main()
{
	foo f;
}
