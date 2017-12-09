// Read line-by-line

#include <sstream>
#include <string>

int main()
{
  std::istringstream stream{"This stream\n"
                            "contains many\n"
                            "lines.\n"};
  std::string line;

  while (std::getline(stream, line)) {
    // Process line
  }
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
// On [13-15], we use a `while` loop to iterate over each line of the
// stream. The condition of the loop is a call to
// [`std::getline`](cpp/string/getline), which extracts lines from
// `stream` into `line`. The result of this call will evaluate to
// `false` only when the extraction fails, such as when there are no
// lines left to extract.
