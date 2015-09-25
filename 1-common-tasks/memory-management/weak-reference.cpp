// Weak reference
// C++11

#include <memory>

class bar;

class foo
{
public:
	foo(const std::shared_ptr<bar>& b)
		: forward_reference{b}
	{ }

private:
	std::shared_ptr<bar> forward_reference;
};

class bar
{
public:
	void set_back_reference(const std::weak_ptr<foo>& f)
	{
		this->back_reference = f;
	}

	void do_something()
	{
		std::shared_ptr<foo> shared_back_reference = this->back_reference.lock();
		if (shared_back_reference) {
			// Use *shared_back_reference
		}
	}

private:
	std::weak_ptr<foo> back_reference;
};

// Maintain a non-owning reference to a shared dynamically allocated
// object to break circular dependencies.
//
// The [`std::weak_ptr`](cpp/memory/weak_ptr) type represents
// a non-owning reference to dynamically allocated object with
// shared ownership ([`std::shared_ptr`](cpp/memory/shared_ptr)). As
// they do not contribute to the reference count of the managed object
// they refer to, the object can be destroyed at any time when all
// `std::shared_ptr`s give up ownership. However, a
// `std::weak_ptr` can be converted to a `std::shared_ptr` to provide
// temporary ownership and safe access to the object.
//
// In this sample, we have two classes: `foo` on [8-17], and `bar` on
// [19-33]. A `foo` object has shared ownership of a `bar` ([16]), and
// `bar` requires some form of reference back to the `foo` that owns it.
// If this back reference were a `std::shared_ptr<foo>`, it would introduce
// a circular dependency, making it impossible for either object to be
// destroyed. If it were a normal reference type (`foo&`), it risks
// refering to a deleted object when it attempts to use it, as the
// lifetime of `foo` is independent of `bar`.
// 
// The solution is to use a `std::weak_ptr<foo>`, as on [36]. When
// `bar` needs to use `foo`, it checks if bar still exists by calling
// `lock` on the `std::weak_ptr` to take temporary shared ownership
// ([29]). If the returned `std::shared_ptr` is not empty, `bar` can
// safely use it to access the `foo` object ([30-32]).

int main()
{
	std::shared_ptr<bar> b = std::make_shared<bar>();
	std::shared_ptr<foo> f = std::make_shared<foo>(b);

	b->set_back_reference(f);

	b->do_something();
}
