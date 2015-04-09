// Function template SFINAE
// C++11

#include <type_traits>
#include <limits>
#include <cmath>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
	equal(T lhs, T rhs)
{
	return lhs == rhs;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type
	equal(T lhs, T rhs)
{
	return std::abs(lhs - rhs) < 0.0001;
}

// Conditionally instantiate a function template depending on the
// template arguments.
// 
// We provide two implementations of the `equal` function template:
// 
// 1. The template on [8-13] will only be instantiated when `T` is an
//    integral type.
// 2. The template on [15-20] will only be instantiated when `T` is a
//    floating point type.
//
// We have used [`std::enable_if`](cpp/types/enable_if) on [9] and
// [16] to force instantiation to succeed only for the appropriate
// template arguments. This relies on [Substitution Failure Is Not An
// Error](http://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error)
// (SFINAE), which states that
// failing to instantiate a template with some particular
// template arguments does not result in an error and simply discards
// that instantiation.
// 
// The second template argument of `std::enable_if` &mdash; in this case,
// `bool` &mdash; is what the full `std::enable_if<...>::type`
// evaluates to when the first template argument is `true`. This means
// that the return type of `equal` will be `bool`.
//
// If you want to simply prevent a template from being instantiated
// for certain template arguments, consider using
// [`static_assert`](cpp/language/static_assert) instead.

int main()
{
	equal(3, 3);
	equal(0.9f / 9.0f, 0.1f);
}
