// Bubble sort
// C++11

#include <iterator>
#include <utility>

template <typename ForwardRange>
void bubble_sort(ForwardRange& range)
{
	using iterator = decltype(std::begin(range));

	iterator begin = std::begin(range);
	iterator end = std::end(range);

	while (end != begin) {
		iterator new_end = begin;

		for (iterator i = begin; std::next(i) != end; std::advance(i, 1)) {
			iterator next = std::next(i);

			if (*next < *i) {
				std::iter_swap(i, next);
				new_end = next;
			}
		}

		end = new_end;
	}
}

// Sort a generic range of elements using the bubble sort algorithm.
// 
// **Note**: The C++ standard library provides a generic
// [`std::sort`](cpp/algorithm/sort) algorithm. This sample is a
// reference implementation for the bubble sort algorithm and should
// not be used in production code.
// 
// We define `bubble_sort` as a template, whose template parameter
// `ForwardRange` must be a range that provides forward iterators.
// The type alias `iterator` on [10] denotes the iterator type for
// the given container, which is the type returned by
// [`std::begin(range)`](cpp/iterator/begin)). Defining it in this
// way allows the function to be used with both containers and normal
// arrays.
// 
// We then create a pair of iterators, `begin` and `end`, denoting
// the start and end of the range ([12-13]). As the `while` loop on
// [15-28] iterates, we will be bubbling the largest elements to the
// end of the range. Because of this, with each iteration we can
// look at a shorter range, bringing `end` closer to `begin` and
// stopping when they are equal.
// 
// The inner loop on [18-25] looks at adjacent pairs of iterators
// between `begin` and `end`, denoted by `i` and `next`. We compare
// the two elements on [21] and swap them over ([22]) if the first is
// greater than the second. This bubbles the largest values to the end
// of the range.
// 
// We keep track of the last `next` element that we swapped into with
// `new_end` ([23]). Every element after this one is guaranteed to be
// sorted (because we didn't do any more swapping), so we can set
// `end` to `new_end`.
// 
// When the `while` loop stops, the range has been fully sorted.
// 
// We have made effective use of generic iterator functions, such as
// [`std::begin`](cpp/iterator/begin), [`std::end`](cpp/iterator/end),
// [`std::next`](cpp/iterator/next), [`std::prev`](cpp/iterator/prev),
// and [`std::advance`](cpp/iterator/advance), so that the algorithm
// can be applied to any range (even a normal array).
 
#include <forward_list>

int main()
{
	std::forward_list<int> arr = {6, 12, 5, 2, 3};
	bubble_sort(arr);
}
