// Pass arrays
// C++11

#include <array>

void compile_time(std::array<int, 3> arr)
{ }

int main()
{
  std::array<int, 3> arr = {4, 8, 15};
  compile_time(arr);
  compile_time({16, 23, 42});
}

// Pass fixed-size arrays to and from functions.
//
// Built-in array types are not copyable, so cannot be passed to and
// from functions by value. The traditional approach is to pass both a
// pointer to an array's first element and the size of the array.
// However, C++ provides a class type that represents a copyable
// fixed-size array.
//
// We define the function `compile_time`, on [6-7], to have a
// parameter of type [`std::array`](cpp/container/array), which represents
// *compile-time* fixed-size arrays. This means that the size must be
// known at compile time. A template may be used to instantiate
// functions for different `std::array` sizes. [!11-13] demonstrate
// passing arrays of size 3 to this function.
