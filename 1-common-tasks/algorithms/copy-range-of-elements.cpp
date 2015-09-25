// Copy a range of elements
// C++11

#include <vector>
#include <algorithm>
#include <iterator>

std::vector<int> target2(5);
std::vector<int> target3;

template <typename RangeOfInts>
void foo(RangeOfInts source)
{
	std::vector<int> target1{std::begin(source),
	                         std::end(source)};

	std::copy(std::begin(source), std::end(source),
	          std::begin(target2));

	std::copy(std::begin(source), std::end(source),
	          std::back_inserter(target3));
}

// Copy elements from a range to another range or container.
// 
// We start with a `source` range object on [12] and, for the purposes
// of this example, we assume its elements are of type `int`.
// 
// On [14-15], we copy the elements from the `source` range into a
// container, `target1`, simply by passing the begin and end iterators
// of the range to the `std::vector<T>`'s constructor. We use
// [`std::begin`](cpp/iterator/begin) and [`std::end`](cpp/iterator/end)
// to obtain these iterators.
//
// To copy the elements of `source` into a range or container which
// already has the appropriate number of elements allocated,
// represented by `target2` on [8], we use [`std::copy`](cpp/algorithm/copy)
// on [17-18]. The first two iterator arguments denote the source
// range, and the third iterator argument denotes the start of the
// target range. For this to work, the elements must already exist in
// the target range.
//
// To demonstrate how we can copy into a container that does not
// yet contain any elements, we have an empty `std::vector<int>`
// called `target3` on [9]. For the third argument of
// `std::copy` ([20-21]), we call [`std::back_inserter`](cpp/iterator/back_inserter)
// to get an iterator that automatically calls `push_back` on `target3`
// for each element that is copied.

int main()
{
	std::vector<int> vec = {5, 4, 3, 2, 1};
	foo(vec);
}
