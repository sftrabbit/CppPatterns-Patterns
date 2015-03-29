// Hide class implementations

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


// elsewhere...

int main()
{
	foo f;
}

// Use the PIMPL idiom to hide class implementations and improve
// compile times.
// 
// A consequence of the C++ compilation model is that any files that
// `#include` a header file will need to be recompiled if that header
// file changes. Since headers with class definitions contain both the
// public and private parts of the class, changing even the internal
// details of the class may require client code to be recompiled. This
// can significantly increase compile times. To overcome this, the PIMPL
// idiom is a method for hiding the implementation of a class from
// users of that class's header file.
// 
// On [7-15], in a header file, we define a public-facing class,
// `foo`, which contains only its public interface and a pointer to an
// internal implementation class. This pointer, on [14], is of type
// [`std::unique_ptr`](cpp/memory/unique_ptr), representing unique
// ownership of the implementation and ensuring that it is safely
// deallocated.
// 
// Notice that the internal implementation class, `impl`, is only
// *forward declared* within the header file &mdash; its definition
// appears in the implementation file on [20-30]. This class contains
// internal data and member functions that might change without
// requiring users of `foo` to recompile.
// 
// [!43] demonstrate that we can use this PIMPL class as we would
// normally because the public interface is unaffected.
