// Observer
// C++11

#include <vector>
#include <functional>

class observer
{
  public:
    virtual void notify() = 0;
};

class observer_concrete : public observer
{
  public:
    virtual void notify() override
    { }
};

class subject
{
  public:
    void register_observer(observer& o)
    {
      observers.push_back(o);
    }

    void notify_observers()
    {
      for (observer& o : observers) {
        o.notify();
      }
    }

  private:
    std::vector<std::reference_wrapper<observer>> observers;
};

// Notify generic observer objects when an event occurs.
//
// The observer pattern allows generic observer objects to be
// registered with a subject object and receive notifications
// when certain events occur.
//
// The `subject` class, defined on [20-37], contains a
// [`std::vector`](cpp/container/vector) of references to observers [36].
// Observers (also known as listeners), in this case, are objects that
// implement the `observer` interface ([7-11]). The
// `register_observer` function ([23-26]) adds observers
// to this `std::vector`, which are later to be notified by the
// `notify_observers` function ([28-33]).
//
// We use [`std::reference_wrapper`](cpp/utility/functional/reference_wrapper)
// for the elements of the `std::vector` ([36]), because the standard
// containers require the element type to be assignable, which normal
// reference types are not.

int main()
{
  subject s;

  observer_concrete o1, o2;
  s.register_observer(o1);
  s.register_observer(o2);

  s.notify_observers();
}
