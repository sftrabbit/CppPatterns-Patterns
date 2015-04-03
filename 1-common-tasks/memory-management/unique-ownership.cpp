// Unique ownership

#include <memory>
#include <utility>

struct foo {};

void pass_unique_ownership(std::unique_ptr<foo> obj)
{ }

int main()
{
	std::unique_ptr<foo> obj1 = std::make_unique<foo>();
	pass_unique_ownership(std::move(obj1));
}

// Transfer unique ownership of a dynamically allocated object to
// another unit of code.
// 
// On [13], we create a [`std::unique_ptr`](cpp/memory/unique_ptr)
// which has ownership of a dynamically allocated `foo` object
// (created with the [`std::make_unique`](cpp/memory/unique_ptr/make_unique)
// utility function). [!14] then demonstrates passing ownership of this
// object to a function. The call to [`std::move`](cpp/utility/move)
// allows the `std::unique_ptr` to be moved into the function.
// 
// In other cases, you may instead wish to
// [share ownership of an object](/common-tasks/memory-management/share-ownership-of-object.html).
