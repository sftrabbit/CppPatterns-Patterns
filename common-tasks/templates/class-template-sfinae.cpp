// Class template SFINAE
// C++11

#include <type_traits>

template <typename T, typename Enable = void>
class foo;

template <typename T>
class foo<T, typename std::enable_if<std::is_integral<T>::value>::type>
{ };

template <typename T>
class foo<T, typename std::enable_if<std::is_floating_point<T>::value>::type>
{ };

// Conditionally instantiate a class template depending on the
// template arguments.
//
// We provide two partial specializations of the `foo` class template:
//
// 1. The template on [9-11] will only be instantiated when `T` is an
//    integral type.
// 2. The template on [13-15] will only be instantiated when `T` is a
//    floating point type.
//
// This allows us to provide different implementations of the `foo`
// class depending on the template arguments it is instantiated with.
//
// We have used [`std::enable_if`](cpp/types/enable_if) on [10] and
// [14] to force instantiation to succeed only for the appropriate
// template arguments. This relies on [Substitution Failure Is Not An
// Error](http://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error)
// (SFINAE), which states that
// failing to instantiate a template with some particular
// template arguments does not result in an error and simply discards
// that instantiation.
//
// If you want to simply prevent a template from being instantiated
// for certain template arguments, consider using
// [`static_assert`](cpp/language/static_assert) instead.

int main()
{
  foo<int> f1;
  foo<float> f2;
}
