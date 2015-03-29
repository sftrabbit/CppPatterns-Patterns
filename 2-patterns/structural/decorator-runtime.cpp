// Decorator (run-time)

class foo
{
	public:
		virtual void do_work() = 0;
};

class foo_concrete : public foo
{
	public:
		virtual void do_work()
		{ }
};

class foo_decorator : public foo
{
	public:
		foo_decorator(foo& f)
			: f(f)
		{ }

		virtual void do_work() {
			// Do something else here to decorate
			// the do_work function
			f.do_work();
		}

	private:
		foo& f;
};

void bar(foo& f)
{
	f.do_work();
}

int main()
{
	foo_concrete f;
	foo_decorator decorated_f{f};

	bar(decorated_f);
}

// Wrap a class with a decorator to extend its functionality.
// 
// On [9-14], we define the class that we wish to decorate,
// `foo_concrete`, which implements the `foo` interface.
// 
// The `foo_decorator` class, on [16-31], also implements the
// `foo` interface. This decorator class wraps any other `foo`
// object, which is passed to the constructor by reference[19-21]
// and decorates its member functions. That is, the
// `foo_decorator::do_work` function ([23-27]) simply calls the
// wrapped object's `do_work` function, while doing some extra work.
// 
// To demonstrate, we wrap a `foo_concrete` with a `foo_decorator` on
// [40-41], and pass it to the `bar` function on [43], which takes a
// reference to any `foo` object and calls `do_work` on it. In this
// case, the call will be decorated by `foo_decorator`.
