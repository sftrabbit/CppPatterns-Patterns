// Shared ownership
// C++11

#include <memory>
#include <utility>

struct foo {};

void func(std::shared_ptr<foo> obj)
{ }

int main()
{
	std::shared_ptr<foo> obj = std::make_shared<foo>();
	func(obj);
}

// Share ownership of a dynamically allocated object with another
// unit of code.
// 
// On [14], we create a [`std::shared_ptr`](cpp/memory/shared_ptr)
// which has ownership of a dynamically allocated `foo` object
// (allocated with the [`std::make_shared`](cpp/memory/shared_ptr/make_shared)
// utility function). [!15] then demonstrates sharing ownership of this
// object with a function. That is, both `main` and `func` have access
// to the same `foo` object. When ownership of an object is shared, it
// will only be destroyed when all `std::shared_ptr`s owning it are
// destroyed.
// 
// In other cases, you may instead wish to [transfer unique ownership
// of an object](/common-tasks/unique-ownership.html).
