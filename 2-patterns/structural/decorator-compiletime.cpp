// Decorator (compile-time)

class foo_concrete
{
	public:
		void do_work()
		{ }
};

template <typename Foo>
class foo_decorator
{
	public:
		foo_decorator(Foo& f)
			: f{f}
		{ }

		void do_work() {
			// Do something else here to decorate
			// the do_work function
			f.do_work();
		}

	private:
		Foo& f;
};

template <typename Foo>
void bar(Foo& f)
{
	f.do_work();
}

int main()
{
	foo_concrete f;
	foo_decorator<foo_concrete> decorated_f{f};

	bar(decorated_f);
}

// Wrap a class with a decorator to extend its functionality.
// 
// On [3-8], we define the class that we wish to decorate,
// `foo_concrete`.
// 
// The `foo_decorator` class template, on [10-26], implements the
// same interface as `foo_concrete` and wraps any other object with
// that interface, passed in to the constructor by reference on
// [14-16]. A `foo_decorator` object can be used anywhere a
// `foo_concrete` would be expected, but also decorates its member
// functions. That is, the `foo_decorator::do_work` function ([18-22])
// calls the wrapped object's `do_work` function, while also doing
// some extra work.
// 
// To demonstrate, we wrap a `foo_concrete` with a `foo_decorator` on
// [36-37], and pass it to the `bar` function template on [39], which
// expects any object that implements the `do_work` function. In this
// case, the call to `do_work` on [31] will be decorated.
