// Swap values

#include <utility>
#include <string>

int main()
{
  std::string s1 = "Hello";
  std::string s2 = "World";

  using std::swap;
  swap(s1, s2);
}

// Swap the values of two objects.
//
// On [8-9], we create two `std::string` objects whose values we wish
// to swap. However, this pattern will also apply to any other [swappable
// type](http://en.cppreference.com/w/cpp/concept/Swappable).
//
// On [11], we use a [using-declaration](cpp/language/using_declaration)
// to make `std::swap` visible and then, on [12], we call unqualified
// `swap` (not `std::swap`) to swap the values of the two objects.
// This allows a user-defined specialization of `swap` to be found
// via [argument-dependent lookup (ADL)](cpp/language/adl), which may
// provide a more efficient implementation of the swap operation,
// before falling back to the generic `std::swap` function. This
// approach is particularly useful when swapping two generic
// objects (such as in a template).
