// Overload operator >>

#include <iostream>
#include <string>

class foo {

private:
	std::string name;

public:
	friend std::istream& operator>>(std::istream&, foo&);
};

std::istream& operator>>(std::istream& is, foo& e) {
	is >> e.name;
	return is;
}

// Write your class type objects to an input stream.
//
// We implemented `operator>>` on line [15-18], which takes
// a reference to an [`std::istream`](cpp/io/basic_istream)
// (the base class for all input streams) and the `foo` object 
// we wish to write to the stream. On line [16], we get input 
// using our a reference to input stream and put whatever entered
// into the class' name attribute. 
// 
// Although there is only one class attribute, we can do the same
// operation with multiple attributes. Be careful that we did not 
// use `const` for parameter object e. Because whenever input stream
// operator is called, we are changing invoked value.

int main() {
	foo f;
	std::cin >> f;

	return 0;
}