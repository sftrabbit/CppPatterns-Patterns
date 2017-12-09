// The PIMPL idiom
// C++11, C++14

// foo.h - header file

#include <memory>

class foo
{
  public:
    foo();
    ~foo();

    foo(foo&&);
    foo& operator=(foo&&);

  private:
    class impl;
    std::unique_ptr<impl> pimpl;
};


// foo.cpp - implementation file

class foo::impl
{
  public:
    void do_internal_work()
    {
      internal_data = 5;
    }

  private:
    int internal_data = 0;
};

foo::foo()
  : pimpl{std::make_unique<impl>()}
{
  pimpl->do_internal_work();
}

foo::~foo() = default;

foo::foo(foo&&) = default;
foo& foo::operator=(foo&&) = default;

// Remove compilation dependencies on internal class implementations
// and improve compile times.
//
// When a header file changes, any files that `#include` that file
// will need to be recompiled. In the case of a class header, this
// is true even if those changes only apply to private members of the
// class. The PIMPL idiom hides private members from any users of
// the header file, allowing these internal details to change without
// requiring recompilation of the client code.
//
// [!8-20] define a class, `foo`, to which we have applied the PIMPL
// idiom. This class definition includes only the public interface
// of the class and a pointer to the internal implementation. We use
// a [`std::unique_ptr`](cpp/memory/unique_ptr) ([19]) to ensure
// the lifetime of the implementation is managed correctly, which we
// initialise in `foo`s constructor ([38]).
//
// While the internal implementation class, `impl`, is declared in
// the header file on [18], its definition appears in the
// implementation file on [25-35]. This allows the class definition
// to change without requiring users of `foo` to recompile.
//
// We have explicitly defaulted `foo`'s destructor on [43], which
// is necessary because the destructor needs to be able to see the
// complete definition of `impl` (in order to destroy the
// `std::unique_ptr`). Note that we have also explicitly defaulted
// the move constructor and assignment operator on [45-46] so that
// `foo` can be moved. To make `foo` copyable, we must also
// implement the copy constructor and assignment operator.
//
// **Note**: `std::make_unique` was introduced in C++14. For C++11,
// you can [roll your own implementation](http://stackoverflow.com/a/17902439/150634).

int main()
{
  foo f;
}
