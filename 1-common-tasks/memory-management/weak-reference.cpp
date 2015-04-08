// Weak Reference

#include <algorithm>
#include <functional>
#include <memory>
#include <vector>

class observer
{
public:
	virtual void notify() = 0;
};

class observer_concrete : public observer
{
public:
	virtual void notify() override {}
};

class subject
{
public:
	void register_observer(const std::shared_ptr<observer>& so)
	{
		std::weak_ptr<observer> wo = so;
		observers.push_back(wo);
	}

	void notify_observers()
	{
		for (std::weak_ptr<observer>& o : observers) {
			std::shared_ptr<observer> so = o.lock();
			if (so)
				so->notify();
		}

		std::remove_if(
			std::begin(observers),
			std::end(observers),
			[] (const std::weak_ptr<observer>& o) { return o.expired(); });
	}

private:
	std::vector<std::weak_ptr<observer>> observers;
};

// Maintain a non-owning (weak) reference to a dynamically allocated object
// managed by a [`std::shared_ptr`].
//
// Weak pointers are non-owning references. As they do not contribute to the
// reference count of the managed object they refer to, the object can be
// deleted by another unit of code at any time. However, a [`std::weak_ptr`] can
// be converted to a [`std::shared_ptr`] to provide temporary ownership and safe
// access to the object.
//
// The observer pattern allows generic observer objects to be registered with a
// subject object and receive notifications when certain events occur. To avoid
// notifying observer objects that have been deleted, and to avoid keeping
// observer objects alive longer than their natural lifetime, we use weak
// pointers.
//
// In this modified example of the observer pattern, the `subject` class,
// defined on [18-42], contains a [`std::vector`](cpp/container/vector),
// `observers`, of weak references to observers. Observers (also known as
// listeners), in this case, are objects that implement the `observer` interface
// ([6-10]). The `register_observer` function ([18-42]) adds weak references to
// the `observers`. To notify the observers, the `notify_observers` function
// ([26-38]) iterates over each weak reference to an observer object, obtains
// temporary ownership by creating a [`std::shared_ptr`] from the
// [`std::weak_ptr`] and checking that the observer object is still alive
// (28-32) before notifying it. To avoid wasting space tracking observer objects
// that have been deleted, expired weak references are purged (34-37).

int main()
{
	subject s;

	std::shared_ptr<observer> o1 = std::make_shared<observer_concrete>();
	s.register_observer(o1);

	{
		std::shared_ptr<observer> o2 = std::make_shared<observer_concrete>();
		s.register_observer(o2);
	}

	s.notify_observers();
}
