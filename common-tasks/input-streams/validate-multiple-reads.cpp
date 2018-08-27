// Validate multiple reads

#include <sstream>
#include <string>

int main()
{
  std::istringstream stream{"Chief Executive Officer\n"
                            "John Smith\n"
                            "32"};

  std::string position;
  std::string first_name;
  std::string family_name;
  int age;

  if (std::getline(stream, position) &&
      stream >> first_name >> family_name >> age) {
    // Use values
  }
}

// Ensure that multiple stream reads are successful before using the
// extracted values.
//
// We create a [`std::istringstream`](cpp/io/basic_istringstream) as
// the example input stream, which contains some values that we wish
// to read ([8-10]). This stream could be replaced by any other
// input stream, such as [`std::cin`](cpp/io/cin) or a file stream.
// We then create some objects on [12-15] into which we will read
// values from the stream.
//
// In the condition of the `if` statement on [17-20], we first perform
// an unformatted extraction with
// [`std::getline`](cpp/string/basic_string/getline) ([17])
// and then a series of formatted extractions ([18]). The `&&` operator
// ensures that the condition is `true` only when all extractions
// succeed. Short-circuiting also ensures that the second set of
// extractions are only attempted if the previous extraction was
// successful.
//
// If you are reading values on multiple lines, consider [reading
// from the stream line-by-line](/patterns/read-line-by-line.html)
// and then parsing each line.
