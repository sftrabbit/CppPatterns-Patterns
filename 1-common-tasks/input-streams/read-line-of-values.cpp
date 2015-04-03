// Read a line of values

#include <vector>
#include <sstream>
#include <iterator>

int main()
{
	std::istringstream stream{"4 36 72 8"};
	std::vector<int> values;

	std::copy(std::istream_iterator<int>{stream},
	          std::istream_iterator<int>{},
	          std::back_inserter(values));
}

// Read a sequence of delimited values from a single line of an
// input stream into a standard container.
// 
// On [9], we declare a [`std::istringstream`](cpp/io/basic_istringstream)
// as the input stream, although any other input stream could be used.
// For user input, you can simply replace `stream` with
// [`std::cin`](cpp/io/cin). We have similarly used
// [`std::vector`](cpp/container/vector) as an example container
// ([10]).
// 
// On [12-14], we use the [`std::copy`](cpp/algorithm/copy) algorithm
// to copy `int`s from the input stream to the container. This
// algorithm takes iterator arguments.
// 
// To iterate over the stream, we use the
// [`std::istream_iterator<int>`](cpp/iterator/istream_iterator) type
// on [12], which internally uses `operator>>` to extract `int`s. The
// default constructed `std::istream_iterator<int>` on [13] denotes
// the end of the stream.
// 
// We use the [`std::back_inserter`](cpp/iterator/back_inserter)
// helper function on [14] to create an output iterator that will
// `push_back` elements into the given container.
