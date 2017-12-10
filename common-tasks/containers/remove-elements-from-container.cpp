// Remove elements from a container
// C++11

#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> v = {1, 2, 3, 4, 2, 5, 2, 6};

  v.erase(std::remove(std::begin(v), std::end(v), 2),
          std::end(v));

  v.erase(std::remove_if(std::begin(v), std::end(v),
                         [](int i) { return i%2 == 0; }),
          std::end(v));
}

// Use the erase-remove idiom to remove elements from a container.
//
// On [9], we create a [`std::vector`](cpp/container/vector) as an example
// container and initialize it some `int` elements.
//
// The [`std::remove` and `std::remove_if`](cpp/algorithm/remove)
// algorithms do not have knowledge about the underlying storage of
// the given range, so cannot actually remove elements from that
// storage. Instead, these algorithms actually shift (by means of move
// assignment) the elements in the range in such a way that the
// elements not removed form a new range at the beginning of the
// original range. The algorithms return a past-the-end iterator for
// this new range, which, since the removed elements have been shifted
// to the end of the original range, also marks the start of the
// removed elements.
//
// On [11-12], we show how we can pass the resulting iterator to the
// container's [`erase`](cpp/container/vector/erase) member function,
// which actually removes the elements from the container. Similarly,
// on [14-16], we demonstrate how `std::remove_if` can be used with
// `erase` to remove all elements for which a given predicate returns
// `true` (in the example code, we remove all even elements).
//
// This technique of using the generic remove algorithms followed by
// a call to the particular container's `erase` member function is
// commonly referred to as the erase-remove idiom.
