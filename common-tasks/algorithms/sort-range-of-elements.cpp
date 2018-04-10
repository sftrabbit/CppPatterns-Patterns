// Sort a range of elements
// C++11

#include <array>
#include <algorithm>
#include <iterator>
#include <functional>

int main()
{
  std::array<int, 5> arr = {3, 4, 1, 5, 2};

  std::sort(std::begin(arr), std::end(arr));

  std::sort(std::begin(arr), std::end(arr),
            std::greater<int>{});
}

// Sort elements in a range into a given order.
//
// On [11], we create a [`std::array`](cpp/container/array) of `int`s
// that we wish to sort.
//
// On [13], we call the standard alrogithm
// [`std::sort`](cpp/algorithm/sort), which sorts the range of
// elements between the given pair of iterators. We use
// [`std::begin`](cpp/iterator/begin) and
// [`std::end`](cpp/iterator/end) to get the begin and end iterators
// for the array.
//
// By default, `std::sort` uses `operator<` to sort the range, which
// arranges the elements in ascending order. It can, however, be
// passed a comparison function object to use when comparing
// elements. On [15-16], we pass an object of type
// [`std::greater<int>`](cpp/utility/functional/greater), which is a
// comparison function object that uses `operator>`. Accordingly, this
// sorts the array in descending order.
