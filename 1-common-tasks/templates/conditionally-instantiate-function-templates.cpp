// Conditionally instantiate function templates

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

int main()
{
	equal(3, 3);
	equal(0.9f / 9.0f, 0.1f);
}

// Use SFINAE to conditionally instantiate function templates.
// 
// We provide two implementations of the `equal` function template:
// the first, on [7-12], is instantiated only for integral
// arguments, such as on [23]; the second, on [14-19], is instantiated
// only for floating point arguments, such as on [24].
// 
// The [Substitution Failure Is Not An
// Error](http://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error)
// (SFINAE) rule states that
// failing to instantiate a template with some particular
// template arguments does not result in an error and that instantiation 
// is simply discarded. On [8] and [15], we use
// [`std::enable_if`](cpp/types/enable_if) to force instantiation to
// succeed only when its first template argument evaluates to `true`
// (in the first case, when `T` is integral, and in the second case,
// when `T` is floating point). The second template argument gives the type
// that it should evaluate to if the condition is true &mdash; that is,
// these functions return `bool`.
// 
// If you want to simply prevent a template from being instantiated
// for certain template arguments, consider using `static_assert`
// instead.
