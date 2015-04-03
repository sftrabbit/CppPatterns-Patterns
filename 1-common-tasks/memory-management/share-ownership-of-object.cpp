// Share ownership of an object

#include <memory>
#include <utility>

struct foo {};

void func(std::shared_ptr<foo> obj)
{ }

int main()
{
	std::shared_ptr<foo> obj = std::make_shared<foo>();
	pass_shared_ownership(obj);
}

// Share ownership of a dynamically allocated object with another
// unit of code.
// 
// On [13], we create a [`std::shared_ptr`](cpp/memory/shared_ptr)
// which has ownership of a dynamically allocated `foo` object
// (allocated with the [`std::make_shared`](cpp/memory/shared_ptr/make_shared)
// utility function). [!14] then demonstrates sharing ownership of this
// object with a function. That is, both `main` and `func` have access
// to the same `foo` object. When ownership of an object is shared, it
// will only be destroyed when all `std::shared_ptr`s owning it are
// destroyed.
// 
// In other cases, you may instead wish to [transfer unique ownership
// of an object](/common-tasks/memory-management/transfer-ownership-of-object.html).
