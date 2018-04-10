// Read text stream

#include <fstream>
#include <sstream>
#include <string>

std::string read_text_stream(std::istream& in)
{
  std::ostringstream ss{};
  ss << in.rdbuf();
  
  return ss.str();
}

// Read entire content of a text stream into a string.
// 
// Sometimes we want to read data from an input stream
// [item-by-item](/common-tasks/read-line-of-values.html) or
// [line-by-line](/common-tasks/read-line-by-line.html). But sometimes
// we want to read the entire stream's text content into a string
// variable, in one shot, without any parsing or formatting.
// 
// On [9] we create a
// [`std::ostringstream`](cpp/io/basic_ostringstream). This is an output
// stream because we are reading *in* from the input stream (`in`), and
// writing what we read *out* to the string stream. We do this on [10],
// using input stream's  [`rdbuf()`](cpp/io/basic_ifstream/rdbuf)
// function to get a pointer to its internal buffer. (We could also have
// used a [`std::streambuf`](cpp/io/basic_streambuf) object directly,
// without requiring a `std::istream` wrapper.)
// 
// If we were able to successfully read the stream's contents, we can
// recover them as a string using `std::ostringstream`'s
// [`str()`](cpp/io/basic_ostringstream/str) function, as on [12].

int main()
{
  std::ifstream in{"file.txt"};
  
  std::string str = read_text_stream(in);
}
