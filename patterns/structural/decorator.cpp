// Decorator

class foo
{
  public:
    virtual void do_work() = 0;
};

class foo_concrete : public foo
{
  public:
    virtual void do_work() override
    { }
};

class foo_decorator : public foo
{
  public:
    foo_decorator(foo& f)
      : f(f)
    { }

    virtual void do_work() override
    {
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

// Extend the functionality of a class.
//
// On [9-14], we define the class that we wish to decorate,
// `foo_concrete`, which implements the `foo` interface.
//
// The `foo_decorator` class, on [16-31], also implements the
// `foo` interface. This decorator class wraps any other `foo`
// object, and forwarding any calls to the wrapped object. By adding
// additional code to `foo_decorator::do_work` ([23-27]), we can
// extend the functionality of the wrapped object.
//
// To demonstrate, we wrap a `foo_concrete` with a `foo_decorator` on
// [40-41], and pass it to the `bar` function on [43], which takes a
// reference to any `foo` object and calls `do_work` on it. In this
// case, the call will be decorated by `foo_decorator`.
