// Copy a range of elements
// C++11

#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
	std::vector<int> source = {1, 2, 3, 4, 5};

	std::vector<int> target1(5);

	std::copy(std::begin(source), std::end(source),
	          std::begin(target1));

	std::vector<int> target2;

	std::copy(std::begin(source), std::end(source),
	          std::back_inserter(target2));
}

// Copy elements from one range to another.
// 
// On [10], we create a [`std::vector<int>`](cpp/container/vector)
// called `source` containing a sequence of values that we wish to copy. 
// 
// On [12], we have another `std::vector<int>`, `target1`, which
// is initialised with 5 elements. We then use
// [`std::copy`](cpp/algorithm/copy) on [14-15] to copy values from
// `source` to `target1`. The first two iterator arguments denote the source
// range, and the third iterator argument denotes the target range.
// We use [`std::begin`](cpp/iterator/begin) and
// [`std::end`](cpp/iterator/end) to get these iterators for
// `source` and `target1`.
//
// To demonstrate how we can copy into a container that does not
// yet contain any elements, we create an empty `std::vector<int>`
// called `target2` on [17]. For the third argument of
// `std::copy` ([19-20]), we call [`std::back_inserter`](cpp/iterator/back_inserter)
// to get an iterator that automatically calls `push_back` on `target2`
// for each element that is copied.
