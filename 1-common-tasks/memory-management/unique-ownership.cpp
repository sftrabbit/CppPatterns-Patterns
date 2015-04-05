// Unique ownership

#include <memory>
#include <utility>

struct foo {};

void func(std::unique_ptr<foo> obj)
{ }

int main()
{
	std::unique_ptr<foo> obj = std::make_unique<foo>();
	func(std::move(obj));
}

// Transfer unique ownership of a dynamically allocated object to
// another unit of code.
// 
// On [13], we create a [`std::unique_ptr`](cpp/memory/unique_ptr)
// which has ownership of a dynamically allocated `foo` object
// (created with the [`std::make_unique`](cpp/memory/unique_ptr/make_unique)
// utility function). [!14] then demonstrates passing ownership of this
// object to the function `func`. After passing ownership, `main` no
// longer has access to the `foo` object. The call to
// [`std::move`](cpp/utility/move) is required to allow the
// `std::unique_ptr` to be moved into the function.
// 
// In other cases, you may instead wish to
// [share ownership of an object](/common-tasks/memory-management/share-ownership-of-object.html).
