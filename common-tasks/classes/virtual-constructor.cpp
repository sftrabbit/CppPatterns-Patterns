// Virtual constructor
// C++11

#include <memory>

class Base
{
public:
  virtual ~Base() {}

  virtual Base* clone() const = 0;
};

class Derived : public Base
{
public:
  Derived* clone() const override
  {
    return new Derived(*this);
  }
};

void foo(std::unique_ptr<Base> original)
{
  std::unique_ptr<Base> copy{original->clone()};
}

// Create a copy of an object through a pointer to its base type.
//
// You can't copy an object unless you know its static type, because
// the compiler must know the amount of space it needs to allocate.
// Therefore we can't copy an object of derived type directly through
// a pointer to its base.
//
// The virtual constructor idiom is a technique for delegating the
// act of copying the object to the derived class through the use of
// virtual functions. To demonstrate, we declare a virtual member
// function of `Base` on [11] (typically named `clone`) that each of
// the derived classes will implement to return a copy of themselves.
// The `Derived` class implements this `clone` function on [17-20],
// simply by creating a copy of itself and returning it.
//
// Now, consider that we are given a `std::unique_ptr<Base>` on [23]
// pointing to an object of derived type that we wish to copy (this
// could alternatively be a `Base*` or any other smart pointer to
// `Base`). To perform this copy, we simply call the virtual `clone`
// member function through the pointer on [25], which thanks to
// polymorphism calls the `Derived` implementation of `clone`,
// returning a pointer that points to a copy of the original derived
// object.
//
// **Note**: It is not possible to implement the virtual constructor
// idiom as-is with smart pointers, as derived virtual member
// functions must have covariant return types. One workaround
// is for `Derived::clone` to return a `Base` pointer instead.
// Alternatively, you can provide non-virtual [wrapper
// functions](http://stackoverflow.com/a/6925201/150634).

#include <utility>

int main()
{
  std::unique_ptr<Base> p = std::make_unique<Derived>();
  foo(std::move(p));
}
