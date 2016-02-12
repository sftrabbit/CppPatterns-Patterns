// The rule of zero

#include <memory>
#include <vector>

class foo
{
	private:
		int x = 10;
		std::vector<int> v = {1, 2, 3, 4, 5};
};

class bar
{
	public:
		std::unique_ptr<int> p = std::make_unique<int>(5);
};

// Utilise the value semantics of existing types to avoid having to
// implement custom copy and move operations.
// 
// The *rule of zero* states that we can avoid writing any custom
// copy/move constructors, assignment operators, or destructors by
// using existing types that support the appropriate copy/move
// semantics.
// 
// The class `foo` on [6-11], for example, does not perform any
// manual memory management, yet correctly supports copies and
// moves without any memory leaks. The defaulted copy/move
// constructors and assignment operators will simply copy or move
// each member. For the `int` `x` ([9]), this will copy its value.
// For `v` ([10]), which is a [`std::vector`](cpp/container/vector),
// all of its elements will be copied over.
// 
// The class `bar` on [13-17] is not copyable by default because it
// has a [`std::unique_ptr`](cpp/memory/unique_ptr) member which
// itself is not copyable. However, it correctly supports move
// operations, which will transfer ownership of the dynamically
// allocated resource.

int main()
{
	foo f1;
	foo f2 = f1;

	bar b1;
	bar b2 = std::move(b1);
}
