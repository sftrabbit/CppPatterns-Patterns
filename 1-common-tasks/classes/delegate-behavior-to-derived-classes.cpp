// Delegate behavior to derived classes

template<typename derived>
class base
{
	public:
		void do_something()
		{
			// ...
			static_cast<derived*>(this)->do_something_impl();
			// ...
		}

	private:
		void do_something_impl()
		{
			// Default implementation
		}
};

class foo : public base<foo>
{
	public:
		void do_something_impl()
		{
			// Derived implementation
		}
};

class bar : public base<bar>
{ };

template<typename derived>
void use(base<derived>& b)
{
	b.do_something();
}

// Delegate behavior to derived classes without incurring the cost of
// run-time polymorphism.
// 
// With the Curiously Recurring Template Pattern (CRTP), which
// provides a form of static polymorphism, we can delegate behavior
// from a base class to its derived classes. This approach avoids the
// costs associated with using `virtual` functions for run-time
// polymorphism, typically implemented with a [virtual function
// table](http://en.wikipedia.org/wiki/Virtual_method_table) (a
// dynamic dispatch mechanism).
// 
// Classes `foo` and `bar`, on [21-31], demonstrate the CRTP idiom by
// inheriting from the `base` class template ([3-19]) and providing
// themselves as the template argument. For example, `foo` inherits
// from `base<foo>` on [21]. This allows `base` to know which
// class it is being inherited by at compile-time.
// 
// The `base` class provides a public member function,
// `do_something` ([7-12]), which depends on `do_something_impl`, an
// internal function that may optionally be overriden by derived
// classes. In this way, `base` is able to delegate behavior to
// derived classes. A default implementation for this function is
// given on [15-18], while the class `foo` provides its own
// implementation on [24-27]. To ensure that the correct
// implementation is used, the `do_something` function casts 
// `this` to a pointer to the derived type on [10] and calls
// `do_something_impl` on it.
// 
// The `use` function template on [33-37] takes a reference to any
// instantiation of `base` and calls `do_something` on it. As the
// derived type is known at compile-time, the correct implementation
// function is called without the need for dynamic dispatch. If a
// `base<foo>` is provided, for example, `foo`'s implementation ([24-27])
// will be invoked. For a `base<bar>`, on the other hand, the
// default implementation defined by `base` will be used ([15-18]).

int main()
{
	foo f;
	use(f);

	bar b;
	use(b);
}
