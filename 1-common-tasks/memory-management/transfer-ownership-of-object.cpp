// Transfer ownership of an object

#include <memory>
#include <utility>

struct foo {};

void pass_unique_ownership(std::unique_ptr<foo> obj)
{ }

std::unique_ptr<foo> return_unique_ownership()
{
	std::unique_ptr<foo> obj = std::make_unique<foo>();
	return std::move(obj);
}

int main()
{
	std::unique_ptr<foo> obj1 = std::make_unique<foo>();
	pass_unique_ownership(std::move(obj1));

	std::unique_ptr<foo> obj2 = return_unique_ownership();
}

// Transfer unique ownership of a dynamically allocated object.
// 
// On [19], we create a [`std::unique_ptr`](cpp/memory/unique_ptr)
// which has ownership of a dynamically allocated `foo` object
// (using the [`std::make_unique`](cpp/memory/unique_ptr/make_unique)
// utility function). [!20] then demonstrates passing ownership of this
// object to a function. The call to [`std::move`](cpp/utility/move)
// allows the `std::unique_ptr` to be moved into the function.
// 
// The `return_unique_ownership` function, on [11-15], demonstrates
// how unique ownership of an object can be passed back out of a
// function. The use of `std::move` on [14] is not strictly necessary
// as `obj` will be implicitly treated as an rvalue in this context.
// This function is called on [22] and ownership transferred to `obj2`.
// 
// In other cases, you may instead wish to
// [share ownership of an object](/common-tasks/memory-management/share-ownership-of-object.html).
