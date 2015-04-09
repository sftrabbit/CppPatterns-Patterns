// Curiously Recurring Template Pattern

#include <iostream>

template<typename derived>
class base {
public:
	// Derived classes may override by defining foo_implementation().
	void foo_interface()
	{
		static_cast<derived*>(this)->foo_implementation();
	}

private:
	void foo_implementation()
	{
		std::cout << "base::foo_implementation called" << std::endl;
	}
};

class bar : public base<bar> {
public:
	void foo_implementation()
	{
		std::cout << "bar::foo_implementation called" << std::endl;
	}
};

class baz : public base<baz> {
};

template<typename derived>
void use(base<derived>& b)
{
	b.foo_interface();
}

int main(int argc, char** argv)
{
	bar b;
    use(b); // Outputs: bar::foo_implementation called

	baz f;
    use(f); // Outputs: base::foo_implementation called
}

// Provide common methods, with default implementations, that can be overriden
// by derived classes without the runtime overhead of virtual methods. This form
// of static polymorphism is less flexible than the runtime equivalent, but
// works for both instance and class (static) methods.
//
// The `base` class uses the Curiously Recurring Template Pattern to provide a
// default implementation of its `foo_interface` [7-10] method. Derived classes
// may then, optionally, override the method.
//
// The `bar` derived class overrides the method [21-24] and so `bar`'s
// implementation is invoked at runtime [39] and [33]. The `baz` derived class does
// not override the method, but still benefits from the default implementation
// that gets called at runtime instead [42] and [33].

