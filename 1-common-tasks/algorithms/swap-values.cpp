// Swap two values

#include <utility>

int main()
{
	int a = 0;
	int b = 1;

	using std::swap;
	swap(a, b);
}

// Swap the values of two objects.
// 
// On [7-8] we create a pair of `int`s whose values we wish to swap.
// 
// On [10] we use a [`using` declaration](cpp/language/using_declaration)
// to make `std::swap` visible.
// 
// On [11] we call `swap()` (not `std::swap()`) to swap the values
// of the two objects.
// After this line, the value of `a` is `1`, and the value of `b` is `0`.
// 
// We use this pattern in order to take advantage of
// [argument-dependent lookup (ADL)](cpp/language/adl).
// ADL can find a more efficient swap implementation if one exists,
// but thanks to the `using` declaration we still have `std::swap`
// available as a fallback.
// 
// If we just did the qualified call `std::swap(a, b)`, it would work
// for almost all types, but it might be sub-optimal.
// When we make an unqualified call to `swap()`, ADL will automatically
// find a customized swap implementation if one exists.
// We declare `std::swap` with a `using` declaration so if a customized
// implementation isn't found, it will fall back on `std::swap`.
