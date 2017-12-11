// Return multiple values

#include <tuple>

std::tuple<int, bool, float> foo()
{
  return {128, true, 1.5f};
}

int main()
{
  std::tuple<int, bool, float> result = foo();
  int value = std::get<0>(result);

  auto [value1, value2, value3] = foo();
}

// Return multiple values of different types from a function.
//
// The `foo` function on [5-8] returns a [`std::tuple`](cpp/utility/tuple)
// representing multiple values of different types.
//
// On [12], we call this function and store the result. We then get
// the first of the returned values with [`std::get`](cpp/utility/tuple/get)
// on [13].
//
// Alternatively, on [15] we use a [structured binding declaration](cpp/language/structured_binding)
// to declare and initialize variables with the returned values. The
// types of these variables are deduced automatically.
//
// If the values are closely and logically related, consider composing
// them into a `struct` or `class` type.
