// Range-based algorithms
// C++11

#include <iterator>
#include <utility>

template <typename ForwardRange>
void algorithm(ForwardRange& range)
{
  using std::begin;
  using std::end;

  using iterator = decltype(begin(range));

  iterator it_begin = begin(range);
  iterator it_end = end(range);

  // Now use it_begin and it_end to implement algorithm
}

// Implement algorithms that can be applied to any generic range of
// elements.
//
// **Note**: The existing algorithms in the standard library are not
// range-based but iterator-based. However, the Ranges Technical
// Specification is experimenting with introducing ranges and
// range-based algorithms to the standard, which are more flexible and
// provide a simpler interface to client code.
//
// [!7-19] define a function template representing a range-based
// algorithm. It takes a single range argument, which is
// any type that supports `begin` and `end` functions that provide
// iterators to the beginning and end of the range. A range may
// be classified depending on the iterators that it provides:
//
// - *Forward Range* - provides
//   [Forward Iterators](cpp/concept/ForwardIterator)
// - *Bidirectional Range* - provides
//   [Bidirectional Iterators](cpp/concept/BidirectionalIterator)
// - *Random Access Range* - provides
//   [Random Access Iterators](cpp/concept/RandomAccessIterator)
//
// For the example code, we assume that the algorithm requires only Forward
// Iterators, so can be applied to any Forward Range. We therefore
// name the template parameter `ForwardRange` on [7] to illustrate
// this.
//
// On [15-16], we call `begin` and `end` on the range to get the
// respective iterators to the beginning and end of the range.
// We use using-declarations on [10-11] to
// allow these calls to be found via [argument-dependent
// lookup](http://en.wikipedia.org/wiki/Argument-dependent_name_lookup)
// before using the standard [`std::begin`](cpp/iterator/begin) and
// [`std::end`](cpp/iterator/end) functions. With these iterators, we
// can now implement the algorithm over the elements between them.
//
// If the iterators are not necessary to implement the algorithm, we
// may instead be able to use a simple
// [range-based `for` loop](/patterns/range-iteration.html).

#include <forward_list>

int main()
{
  std::forward_list<int> arr = {6, 12, 5, 2, 3};
  algorithm(arr);
}
