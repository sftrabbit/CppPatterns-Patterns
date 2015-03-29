// Return multiple values

#include <tuple>
#include <string>

std::tuple<int, bool, std::string> foo()
{
	return {128, true, "hello"};
}

int main()
{
	int obj1;
	bool obj2;
	std::string obj3;

	std::tie(obj1, obj2, obj3) = foo();
}

// Return multiple values of different types from a function.
// 
// The `foo` function on [6-9] returns a
// [`std::tuple`](cpp/utility/tuple) representing multiple values
// of different types.
// 
// On [17], the [`std::tie`](cpp/utility/tuple/tie) helper function
// ensures that each of the return values is assigned to each of the
// given objects. This approach only works if it is reasonable to
// declare the objects earlier.
// 
// When we cannot use `std::tie`, we can simply
// store the resulting `std::tuple` object and use
// [`std::get`](cpp/utility/tuple/get) to get the values from it.
