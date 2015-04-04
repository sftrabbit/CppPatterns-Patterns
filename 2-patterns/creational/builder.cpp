// Builder

#include <vector>

class foo
{
	public:
		class builder;

		foo(int prop1, bool prop2, bool prop3, std::vector<int> prop4)
			: prop1{prop1}, prop2{prop2}, prop3{prop3}, prop4{prop4}
		{ }

		int prop1;
		bool prop2;
		bool prop3;
		std::vector<int> prop4;
};

class foo::builder
{
	public:
		builder& set_prop1(int value) { prop1 = value; return *this; };
		builder& set_prop2(bool value) { prop2 = value; return *this; };
		builder& set_prop3(bool value) { prop3 = value; return *this; };
		builder& set_prop4(std::vector<int> value) { prop4 = value; return *this; };

		foo build() const
		{
			return foo{prop1, prop2, prop3, prop4};
		}

	private:
		int prop1 = 0;
		bool prop2 = false;
		bool prop3 = false;
		std::vector<int> prop4 = {};
};

int main()
{
	foo f = foo::builder{}.set_prop1(5)
	                      .set_prop3(true)
	                      .build();
}

// Separate the complex construction of an object from its
// representation.
// 
// The `foo` class, on [5-18], has a complex construction process
// during which any subset of its properties might be set. This
// process is captured by the `foo::builder` class, on [20-38].
// This builder class provides an interface for
// constructing `foo` objects, allowing various combinations of
// parameters to be provided. This avoids having to define a large
// collection of constructors for `foo`.
// 
// The `foo::builder` class implements a set of
// chainable functions for setting the construction parameters
// ([23-26]) and a `build` member function for constructing the `foo`
// object with these parameters ([28-31]).
// 
// On [42-44], we use `foo::builder` to construct a `foo` object,
// setting its `prop1` and `prop3` members and calling `build` to
// construct the object.
