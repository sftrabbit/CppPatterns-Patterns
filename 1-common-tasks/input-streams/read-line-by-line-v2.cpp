// Read line-by-line v2

#include <sstream>
#include <string>

int main()
{
	std::istringstream stream{"This stream\n"
	                          "contains many\n"
	                          "lines.\n"};

	for (std::string line; std::getline(stream, line);) {
		// Process line
	}

	// 'line' is out of scope
}

// Process the contents of an input stream line-by-line.
// 
// We use a [`std::istringstream`](cpp/io/basic_istringstream) as an
// example input stream ([8-10]) containing multiple lines (separated
// by `\n`). This stream could be replaced with
// [`std::cin`](cpp/io/cin) or a file stream, for example. On [11], we
// introduce a [`std::string`](cpp/string/basic_string) into which we
// will read each line of the stream.
// 
// On [12-14], we use a `for` loop declaring a std::string line to 
// accomodate each line content of the stream. The condition of the
// loop is a call to [`std::getline`](cpp/string/getline), which
// extracts lines from `stream` into `line`. The result of this call
// will evaluate to `false` only when the extraction fails, such as
// when there are no lines left to extract.
