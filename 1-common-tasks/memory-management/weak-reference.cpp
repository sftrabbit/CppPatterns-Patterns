// Weak Reference

#include <iostream>
#include <memory>

class foo;

class bar
{
public:
	void set_foo(const std::shared_ptr<foo>& foo)
	{
		this->sp = foo;
	}

	void notify_ready() {}

private:
	std::shared_ptr<foo> sp;
};

class foo
{
public:
	void set_bar(const std::weak_ptr<bar>& bar)
	{
		this->wp = bar;
	}

	void start()
	{
		std::shared_ptr<bar> sp = this->wp.lock();
		if (sp)
			sp->notify_ready();
	}

private:
	std::weak_ptr<bar> wp;
};



// Maintain a non-owning (weak) reference to a dynamically allocated object
// managed by a [`std::shared_ptr`](cpp/memory/shared_ptr) to avoid a circular
// dependency.
//
// Weak pointers are non-owning references. As they do not contribute to the
// reference count of the managed object they refer to, the object can be
// deleted by another unit of code at any time. However, a
// [`std::weak_ptr`](cpp/memory/weak_ptr) can be converted to a
// [`std::shared_ptr`] to provide temporary ownership and safe
// access to the object.
//
// In this example a bar object may depend on a foo object and should be
// notified when the foo is ready. However bar's lifetime is independent of
// foo's. If foo stores a plain reference to bar, it risks refering to a
// deleted object when it attempts to notify bar. If foo stores a
// [`std::shared_ptr`] to bar, it introduces a circular dependency,
// unnecessarily preventing foo from being deleted. The solution is to use a
// [`std::weak_ptr`]. When foo is started, it checks if bar still exists by
// attempting to take temporary ownership and then notifies bar that it is
// ready (30-32).

int main()
{
	std::shared_ptr<foo> f = std::make_shared<foo>();

	{
		std::shared_ptr<bar> b = std::make_shared<bar>();
		b->set_foo(f);
		f->set_bar(b);
	}

	f->start();
}
