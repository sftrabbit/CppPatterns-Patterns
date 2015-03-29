// Conditionally instantiate class templates

#include <type_traits>
#include <limits>

template <typename T, typename Enable = void>
class foo;

template <typename T>
class foo<T, typename std::enable_if<std::is_integral<T>::value>::type>
{ };

template <typename T>
class foo<T, typename std::enable_if<std::is_floating_point<T>::value>::type>
{ };

int main()
{
	foo<int> f1;
	foo<float> f2;
}

// Use SFINAE to conditionally instantiate class templates.
// 
// We provide two partial specializations of the `foo` class template:
// the first, on [9-11], is instantiated only for integral
// type, such as on [19]; the second, on [13-15], is instantiated
// only for floating point types, such as on [20].
// 
// The [Substitution Failure Is Not An
// Error](http://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error)
// (SFINAE) rule states that
// failing to instantiate a template with some particular
// template arguments does not result in an error and that instantiation 
// is simply discarded. On [10] and [14], we use
// [`std::enable_if`](cpp/types/enable_if) to force instantiation to
// succeed only when its first template argument evaluates to `true`
// (in the first case, when `T` is integral, and in the second case,
// when `T` is floating point). If neither case succeeds, the compiler
// will attempt to instantiate the undefined unspecialized template on
// [6-7] and give an error.
// 
// If you want to simply prevent a template from being instantiated
// for certain template arguments, consider using `static_assert`
// instead.
