// Insertion sort

#include <iterator>
#include <utility>

template <typename BidirectionalRange>
void insertion_sort(BidirectionalRange& range)
{
	using Iter = decltype(std::begin(range));
	using RIter = std::reverse_iterator<Iter>;

	const Iter begin = std::begin(range);
	const Iter end = std::end(range);
	const RIter rend = RIter(begin);

	for (Iter j = std::next(begin); j != end; std::advance(j, 1)) {
		typename std::iterator_traits<Iter>::value_type key = *j;

		RIter i = RIter(j);
		for (; i != rend && *i > key; std::advance(i, 1)) {
			*std::prev(i) = *i;
		}
		*std::prev(i) = key;
	}
}

// Sort a generic range of elements in a nondecreasing order using
// insertion sort algorithm.
//
// `insertion_sort` is a template function, whose template parameter
// `BidirectionalRange` must be a range that provides forward and
// reverse type of iterators.
//
// The type aliases `Iter` on [9] and `RIter` on [10] denote the
// forward and reverse iterator types respectively (for the given
// container). Forward iterator type is acquired by
// [`std::begin(range)`](cpp/iterator/begin)). Since `std::begin()` is
// defined for both containers and normal arrays this allows the
// function to be used with both containers and normal arrays.
//
// Constant iterators `begin` ([12]) and `end` ([13]) denote
// boundaries for the forward traversal of the container. Constant
// iterator `rend` is the reverse traversal boundary ([14]).
//
// Outer loop on [16-24] iterates from the second element in the
// container to the last one.
//
// Inside the outer loop, we first save the value of the current
// element in the `key` ([17]).
//
// Insertion sort relies on the fact that all elements before the
// current element of the outer loop are already sorted.  All we need
// to do in the each step of outer loop is to find the proper place to
// insert the `key` value in the already sorted part of the container.
//
// To accomplish this, we first acquire reverse iterator ([19]) that
// points to the first element before current element of the outer
// loop (check image in
// [`std::list::rbegin`](cpp/container/list/rbegin) for more
// information about forward and reverse iterators.) This iterator is
// used to traverse backwards through the sorted part of the container
// (as long as the current element of the inner loop is bigger than
// `key`, [20]). In each step of inner loop, current element is moved
// one spot further in the container.
//
// Described behavior of the inner loop always leaves hole in the
// sorted part of the container after the loop terminates. In [24] we
// insert previously saved `key` in that position - since all the
// elements on it's left should be lower than `key` and all elements
// on the right are higher.
//
// We have made effective use of generic iterator functions, such as
// [`std::begin`](cpp/iterator/begin), [`std::end`](cpp/iterator/end),
// [`std::next`](cpp/iterator/next), [`std::prev`](cpp/iterator/prev),
// and [`std::advance`](cpp/iterator/advance), so that the algorithm
// can be applied to any range (even a normal array).

#include <list>
#include <cassert>

int main()
{
	// Basic test
	int arr_start[]  = {6, 12, 5, 2, 3};
	int arr_sorted[] = {2, 3, 5, 6, 12};
	insertion_sort(arr_start);
	assert(std::equal(std::begin(arr_start), std::end(arr_start),
			std::begin(arr_sorted)));

	// Test sorting stability
	typedef std::pair<int, int> pii;
	std::list<pii> arr_pii_start  =
		{ {3,0}, {4,0}, {1,0}, {8,0}, {9,0}, {4,1}, {3,1}, {2,0}, {9,1},
			{1,1}, {2,1}, {8,1}, {3,2}, {5,0}, {7,0} };
	std::list<pii> arr_pii_sorted =
		{ {1,0}, {1,1}, {2,0}, {2,1}, {3,0}, {3,1}, {3,2}, {4,0}, {4,1},
			{5,0}, {7,0}, {8,0}, {8,1}, {9,0}, {9,1} };
	insertion_sort(arr_pii_start);
	assert(arr_pii_start == arr_pii_sorted);
}
