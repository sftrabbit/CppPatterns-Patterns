// Virtual constructor idiom
// C++11

#include <memory>

class IBase
{
public:
	virtual ~IBase() {}

	virtual IBase* clone() const = 0;
};

class Derived1 : public IBase
{
public:
	IBase* clone() const override
	{
		return new Derived1(*this);
	}
};

class Derived2 : public IBase
{
public:
	IBase* clone() const override
	{
		return new Derived2(*this);
	}
};

class Foo
{
public:
	Foo() 
		: basePtr(new Derived1())
	{}

	Foo(const Foo& other) 
		: basePtr(other.basePtr->clone())
	{}

private:
	std::unique_ptr<IBase> basePtr;
};


// To create a copy of an object without knowing its concrete type.
//
// In C++, you can't copy an object unless you know it's exact type.
// This is because the compiler must know the amount of space it 
// needs to allocate. Therefore we can't copy instances of derived 
// classes through the pointer to base. If You we want to copy Foo, 
// we need to implement a copy constructor that will initialize
// Foo::basePtr [44]. Obviously we want it to be the same as original 
// but how do we do that not knowing the type of the original?
//
// The answer is to use the "virtual constructor idiom" which allows 
// to "Create a copy of an object without knowing it's concrete type" 
// The "trick" is to declare a method in the base class that each of 
// the derived classes will implement to return a copy of itself.
// Let's call it "clone()" [11] (Note that it's a pure-virtual method 
// which forces every derived class to implement it.)
// Each of the derived classes now implements clone() by simply 
// returning a copy of itself. [19] [28]
// The type of '*this' in this case is 'const Class&' (a reference to
// const) so Class(*this) calls a copy constructor.
// (Note, that the clone() method might not be marked const in which 
// case *this returns a non-const reference. Proper copy constructor 
// is still called, but it's a good habit to mark methods that don't 
// modify the class with 'const')
//
// Now, if we want to properly copy Foo::basePtr, in the Foo's copy 
// constructor [39-41] we just call IBase->clone() [40] which thanks 
// to polymorphism returns a pointer that points to a copy of the 
// original derived instance.
// 
// Note that this idiom is most usefull when derived classes have 
// some state, which in this example, for the sake of simplicity, 
// is omitted.

int main()
{
	Foo f1;
	Foo f2(f1);
}
