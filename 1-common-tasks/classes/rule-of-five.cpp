// The rule of five
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

		foo& operator=(const foo& other)
		{
			if (&other != this) {
				delete p;
				p = nullptr;
				p = new resource{*(other.p)};
			}

			return *this;
		}

		foo& operator=(foo&& other)
		{
			if (&other != this) {
				delete p;
				p = other.p;
				other.p = nullptr;
			}

			return *this;
		}

		~foo()
		{
			delete p;
		}

	private:
		resource* p;
};

// Safely and efficiently implement RAII to encapsulate the
// management of dynamically allocated resources.
// 
// The rule of five is a modern expansion of the rule of three.
// Firstly, the *rule of three* specifies that if a class implements
// any of the following functions, it should implement all of them:
// 
// - copy constructor
// - copy assignment operator
// - destructor
// 
// These functions are usually required only when a class is manually
// managing a dynamically allocated resource, and so all of them must
// be implemented to manage the resource safely.
// 
// In addition, the *rule of five* identifies that it usually
// appropriate to also provide the following functions to allow for
// optimized copies from temporary objects:
// 
// - move constructor
// - move assignment operator
// 
// The class `foo`, on [10-56], dynamically allocates a `resource`
// object in its constructor. The implementations of `foo`'s
// copy constructor ([17-19]), copy assignment operator ([27-36]),
// and destructor ([49-52]) ensure that the lifetime of this
// resource is safely managed by `foo` object that contains it,
// even in the event of an exception.
// 
// We have also implemented a move constructor ([21-25]) and
// move assignment operator ([38-47]) that provide optimized copies
// from temporary objects. Rather than copy the resource, they
// take the resource from the original `foo` and set its 
// internal pointer to `nullptr`, effectively stealing the resource.
// 
// Notice that the assignment operators ([27-47]) check for
// self-assignment to ensure safe management of the resource.
// 
// **Note**: The copy and move assignment operators in this sample
// provide only basic exception safety. They may alternatively be
// implemented with [the copy-and-swap
// idiom](/common-tasks/copy-and-swap.html), which provides strong
// exception safety at an optimisation cost.
// 
// **Note**: We can typically avoid manual memory management and
// having to write the copy constructor, assignment operator, and
// destructor entirely by using the
// [rule of zero](/common-tasks/rule-of-zero.html)

int main()
{
	foo f;
}
