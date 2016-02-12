// Count occurrences of value in a range

# include <iostream>
# include <algorithm>
# include <vector>

int main()
{
	std::vector<int> numbers = {1, 2, 3, 5, 6, 3, 4, 1};

	int count = std::count(std::begin(numbers),
	                       std::end(numbers),
	                       3);
}

// Count the number of occurrences of a particular value in a range of
// elements.
//
// On [9], we create a [`std::vector`](cpp/container/vector) of `int`
// initialized with some values.
//
// On [11-13], we use the alrogithm [`std::count`](cpp/algorithm/count),
// to count the occurrences of a particular value in the `std::vector`.
// For the first two arguments on [11-12], we use [`std::begin`](cpp/iterator/begin)
// and [`std::end`](cpp/iterator/end) to get the begin and end
// iterators for the range in which we wish to count. The third
// argument on [13] is the value to count the occurrences of.
//
// To count elements according to a predicate, you can use
// [`std::count_if`](cpp/algorithm/count) instead.
