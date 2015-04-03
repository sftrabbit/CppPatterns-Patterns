// The PIMPL idiom

// foo.h - header file

#include <memory>

class foo
{
	public:
		foo();

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

// Reduce dependencies on internal class implementations and improve
// compile times.
// 
// When a header file changes, any files that `#include` that file
// will need to be recompiled. In the case of a class header, this
// is true even if those changes only apply to private members of the
// class. The PIMPL idiom hides private members from any users of
// the header file, allowing these internal details to change without
// requiring recompilation of the client code.
// 
// [!7-15] define a class, `foo`, to which we have applied the PIMPL
// idiom. This class definition includes only the public interface
// of the class and a pointer to the internal implementation. We use
// a [`std::unique_ptr`](cpp/memory/unique_ptr) ([14]) to ensure
// the lifetime of the implementation is managed correctly, which we
// initialise in `foo`s constructor ([33]).
// 
// While the internal implementation class, `impl`, is declared in
// the header file on [13], its definition appears in the
// implementation file on [20-30]. This allows the class definition
// to change without requiring users of `foo` to recompile.

int main()
{
	foo f;
}
