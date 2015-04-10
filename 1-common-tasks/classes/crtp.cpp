// Compile-time interfaces 
// CRTP, templates, interfaces, polymorphism

// interface.h

template <typename Impl>
struct interface
{
		bool hasCompleted()
		{
			return static_cast<Impl*>(this)->hasCompleted();
		}

		void doOperation(bool verbose)
		{
			return static_cast<Impl*>(this)>doOperation(verbose);
		}	
};


// implementation.h - header file

class implementation : public interface<implementation> 
{
	public:
		bool hasCompleted();
		void doOperation(bool waitForIt);

	private:
		bool _waitForIt = false;
};


// implementation.cpp - implementation file

bool implementation::hasCompleted()
{
	return !_waitForIt;
}

void implementation::doOperation(bool waitForIt)
{
	_waitForIt = waitForIt;
}


// Enforce that a type implement a particular interface, without
// incurring the cost of runtime polymorphism.
// 
// Interfaces provide a abstraction mechanism that encourages low
// coupling between types and allows for flexibility as code evolves.
// C++ has no formal concept for an interface (at least until
// (Concepts)[http://en.cppreference.com/w/cpp/concept] have been
// incorporated into the standard. The closest alternative is to
// create a base type that contains only 'pure-virtual' methods
// (except for the constructor and destructor). That technique
// imposes the overhead of runtime polymorphism, which might be
// undesirable in certain situations. The Curiously Recurring
// Template Pattern (CRTP) allows us to create an interface with no
// such overhead, at the cost of some slightly odd-looking code.
// 
// [!3-15] define an interface using the CRTP technique. In this
// type, the implementation of interface methods will delegate the
// behavior to a method on the `Impl` type with the same signature. 
// Because of the way that templates are parsed, when the compiler
// sees that `implementation` derives from `interface<implementation`
// it will instantiate the template, and it proceeds to verify that
// the type provided to the template can satisfy the implicit
// requirements contained within the `interface` class template.

#include <iostream>

int main()
{
	implementation impl;
        std::cout << impl.hasCompleted();
	impl.doOperation(true);
	std::cout << impl.hasCompleted();
}
