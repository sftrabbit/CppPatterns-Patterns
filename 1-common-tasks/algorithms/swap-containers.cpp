// Swap the contents of two containers

#include <algorithm>
#include <utility>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1, 3, 5, 7 };
	std::vector<int> v2 = { 2, 4, 6, 8 };

	std::swap_ranges(std::begin(v1), std::end(v1), std::begin(v2));

	v1.swap(v2);

	using std::swap;
	swap(v1, v2);
}

// Swap the contents of two containers.
// 
// On [9-10] we create a pair of `vectors`s, and fill them with values.
// 
// On [12] we swap the contents of the two vectors using
// [`std::swap_ranges`](cpp/algorithm/swap_ranges), which goes through
// two ranges and does an element-by-element swap of their values.
// (So in this example, it does four swaps - one for each of the four
// elements in the `vector`s.)
// 
// On [14] we swap the `vector`s' contents all in one shot - not
// element-by-element.
// (`v2.swap(v1)` would have the same effect.)
// 
// On [16-17] we again swap the `vector`s all in one shot, this time
// using the generic swap pattern.
// 
// The difference between `swap_ranges()` and the `swap()` methods is
// that `swap_ranges()` goes through both containers element-by-element
// and swaps each pair of elements individually, while `swap()` (either
// the member function or the generic non-member function) swaps the
// *entire* container at once.
// The two methods each have their pros and cons.
// 
// `swap_ranges()` is generally much slower than `swap()`, because it
// has to swap each pair of values one at a time, rather than all at
// once.
// It also requires that both of the ranges we swap are the same size.
// However, it does not invalidate the iterators of the container, and
// it allows us to swap *portions* of a container - even within
// the same container (for example, if your container has 10 or more
// elements we could swap the first 5 elements with the last 5).
// 
// `swap()` is usually *much* faster than `swap_ranges()` - for large
// containers it can be thousands or millions of times faster (but
// this is not true for *all* container types).
// `swap()` can swap the contents of two containers even if they are
// not the same size (so we can swap a container with 100 elements
// with an empty container).
// However, it will invalidate the container's iterators, and there is
// no option to swap only portions of a container with `swap()`.
