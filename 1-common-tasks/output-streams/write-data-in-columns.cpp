// Write data in columns

#include <iostream>
#include <iomanip>

int main()
{
	std::cout << std::left << std::setw(12) << "John Smith"
	          << std::right << std::setw(3) << 23
	          << '\n';
	std::cout << std::left << std::setw(12) << "Sam Brown"
	          << std::right << std::setw(3) << 8
	          << '\n';
}

// Align data in columns when writing to an output stream.
// 
// On [8-13], we write two lines of data to an output stream.
// [`std::cout`](cpp/io/cout) is used as the example stream.
// 
// We use I/O manipulators to align the data in columns. The
// [`std::setw`](cpp/io/manip/setw) manipulator sets the
// width of a column, while [`std::left`](cpp/io/manip/left) and
// [`std::right`](cpp/io/manip/left) set the alignment of the
// written value within that column. For example, on [8], we
// write the name "John Smith" to a column of width 12 and align
// it to the left of the column.
