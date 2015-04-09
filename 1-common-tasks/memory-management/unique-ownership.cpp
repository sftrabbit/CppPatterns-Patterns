// Unique ownership
// C++11, C++14

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
// On [14], we create a [`std::unique_ptr`](cpp/memory/unique_ptr)
// which has ownership of a dynamically allocated `foo` object
// (created with the [`std::make_unique`](cpp/memory/unique_ptr/make_unique)
// utility function). [!15] then demonstrates passing ownership of this
// object to the function `func`. After passing ownership, `main` no
// longer has access to the `foo` object.
// 
// As `std::unique_ptr` is non-copyable, it must be moved instead of
// being copied. The call to [`std::move`](cpp/utility/move) on [15]
// allows `obj` to be treated like a temporary object (the expression
// `std::move(obj)` is an rvalue) so that it can be moved into the
// function.
// 
// In other cases, you may instead wish to
// [share ownership of an object](/common-tasks/shared-ownership.html).
// 
// **Note**: `std::make_unique` was introduced in C++14. For C++11,
// you can [roll your own implementation](http://stackoverflow.com/a/17902439/150634).
