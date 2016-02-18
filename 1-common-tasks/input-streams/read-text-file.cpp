// Read text file

#include <fstream>
#include <sstream>
#include <string>

std::string read_text_file(std::string const& filename)
{
	std::ifstream file{filename};
	
	std::ostringstream ss{};
	ss << file.rdbuf();
	
	return ss.str();
}

// Read an entire text file into a string.
// 
// Sometimes we want to read data from a file
// [item-by-item](/common-tasks/read-line-of-values.html) or
// [line-by-line](/common-tasks/read-line-by-line.html). But sometimes
// we want to read an entire text file into a string variable, in one
// shot, without any parsing or formatting.
// 
// On [9], we create an input stream for the file that we will be
// reading.
// 
// We create a [`std::ostringstream`](cpp/io/basic_ostringstream) on
// [11]; this is an output stream because we are reading *in* from the
// file stream, and writing what we read *out* to the string stream. We
// do this on [12], using file stream's
// [`rdbuf()`](cpp/io/basic_ifstream/rdbuf) function to get a pointer to
// its internal buffer. (We could also have used a
// [`std::filebuf`](cpp/io/basic_filebuf) object directly, without
// a `std::ifstream`.)
// 
// If we were able to successfully read the file's contents, we can
// recover them as a string using `std::ostringstream`'s
// [`str()`](cpp/io/basic_ostringstream/str) function, as on [14].

int main()
{
	std::string str = read_text_file("file.txt");
}
