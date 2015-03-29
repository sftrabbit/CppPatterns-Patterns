// Encapsulate memory management

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

int main()
{
	foo f;
}

// Use the rule of three to implement RAII and safely manage dynamic
// memory allocations.
// 
// The class `foo` dynamically allocates an `int` object in its
// constructor ([9]). To ensure that the lifetime of this `int` is
// tied to the lifetime of the `foo` object that allocated it, 
// we deallocate the object in `foo`'s destructor ([24]). This idiom,
// known as
// [RAII](http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization),
// ensures that dynamically allocated objects are properly destroyed
// and no memory is leaked.
// 
// The *rule of three* states that if a class has a destructor, it
// should likely have a copy constructor and assignment operator
// too. As the destructor is usually necessary only for cleaning up 
// dynamically allocated resources, we also need custom copy
// constructors and assignment operators to handle these resources
// appropriately. We have defined these functions for `foo` on
// [12-20].
// 
// Using existing RAII types from the standard library (such as
// [smart pointers](cpp/memory) or [containers](cpp/container)), we
// can often avoid dynamic resource management altogether. If you do
// require manual resource management, consider making your
// classes moveable, which provides optimized copies from temporary
// objects.
