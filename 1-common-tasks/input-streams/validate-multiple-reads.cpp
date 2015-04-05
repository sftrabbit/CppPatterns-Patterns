// Validate multiple reads

#include <sstream>
#include <string>

int main()
{
	std::istringstream stream{"John Smith 32"};

	std::string first_name;
	std::string family_name;
	int age;

	if (stream >> first_name &&
	    stream >> family_name &&
	    stream >> age) {
		// Use values
	}
}

// Ensure that multiple stream reads are successful before using the
// extracted values.
// 
// We create a [`std::istringstream`](cpp/io/basic_istringstream) as
// the example input stream, which contains some values that we wish
// to read ([8]). This stream could be replaced by any other
// input stream, such as [`std::cin`](cpp/io/cin) or a file stream.
// We then create some objects on [10-11] into which we will read 
// values from the stream.
// 
// In the condition of the `if` statement on [14-16], we perform the
// extractions. The `&&` operators ensure that the condition
// is `true` only when all extractions succeed. Short-circuiting
// also ensures that an extraction is only evaluated if the previous
// extractions were successful.
// 
// If you are reading values on multiple lines, consider [reading
// from the stream line-by-line](/common-tasks/read-line-by-line.html)
// and then parsing each line.
