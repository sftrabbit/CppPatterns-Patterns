// Perfect forwarding
// C++11

#include <utility>

template<typename T, typename U>
std::pair<T, U> make_pair_wrapper(T&& t, U&& u)
{
	return std::make_pair(std::forward<T>(t),
	                      std::forward<U>(u));
}

// Forward arguments of one function to another as though the wrapped
// function had been called directly.
// 
// Perfect forwarding allows us to preserve an argument's value
// category (lvalue/rvalue) and `const`/`volatile` modifiers. Perfect
// forwarding is performed in two steps: receive a *forwarding
// reference* (also known as *universal reference*), then forward it
// using [`std::forward`](cpp/utility/forward).
// 
// In our example, the arguments `t` and `u` on [7] are forwarding
// references because they are declared in the form `X&&` where `X`
// is a template parameter. We use `std::forward` on [9-10] to forward
// these arguments to [`std::make_pair`](cpp/utility/pair/make_pair),
// allowing them to be moved into the pair when the original argument
// was an rvalue expression.
//
// Perfect forwarding is often used with [variadic templates](cpp/language/parameter_pack)
// to wrap calls to functions with an arbitrary number of arguments.
// For example, [`std::make_unique`](cpp/memory/unique_ptr/make_unique)
// and [`std::make_shared`](cpp/memory/shared_ptr/make_shared) both
// use perfect forwarding to forward their arguments to the
// constructor of the wrapped type.

int main()
{
	std::pair<int, int> p1{ make_pair_wrapper(1, 2) };
}
