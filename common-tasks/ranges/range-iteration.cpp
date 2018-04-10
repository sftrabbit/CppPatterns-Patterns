// Range iteration
// C++11

#include <vector>

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  for (int value : arr) {
    // Use value
  }

  std::vector<int> vec = {1, 2, 3, 4, 5};
  for (int& ref : vec) {
    // Modify ref
  }
}

// Iterate over a range of elements without using iterators or
// indices.
//
// The [range-based `for` loop](cpp/language/range-for) provides a
// simple syntax for iterating over elements of a range without using
// iterators or indices. It supports arrays, types that provide
// `begin` and `end` member functions, and types for which `begin`
// and `end` functions are found via [argument-dependent
// lookup](http://en.wikipedia.org/wiki/Argument-dependent_name_lookup).
//
// [!9-11] demonstrate iterating over an array, `arr`. In each iteration,
// `value` will have the value of each successive element of `arr`.
//
// [!14-16] similarly demonstrate iterating over a
// [`std::vector`](cpp/container/vector), `vec` (any standard
// container will also work). In this case, we have defined `ref` as a
// reference type, which will allow us to modify the objects stored
// in `vec`.
