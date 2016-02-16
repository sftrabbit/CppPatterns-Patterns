// Read text file

#include <fstream>
#include <sstream>
#include <string>

int main()
{
  std::ifstream file{"file.txt"};
  if (file)
  {
    std::ostringstream ss{};
    if (ss << file.rdbuf())
    {
      std::string str = ss.str();
    }
  }
}

// Read an entire text file into a string.
// 
// Sometimes we want to read data from a file
// [item-by-item](/common-tasks/read-line-of-values.html) or
// [line-by-line](/common-tasks/read-line-by-line.html). But sometimes
// we want to read an entire text file into a string variable, in one
// shot and without any formatting.
// 
// On [9], we create an input stream for the file `file.txt`, and
// confirm the file was opened successfully on [10].
// 
// We create a [`std::ostringstream`](cpp/io/basic_ostringstream) on
// [12]; this is an output stream because we are reading *in* from the
// file stream, and writing what we read *out* to the string stream. We
// do this on [13], using file stream's
// [`rdbuf()`](cpp/io/basic_ifstream/rdbuf) function to get a pointer to
// its internal buffer. (We could also have used a
// [`std::filebuf`](cpp/io/basic_filebuf) object directly, without
// a `std::ifstream`.)
// 
// If we were able to successfully read the file's contents, we can
// recover them as a string variable using `std::ostringstream`'s
// [`str()`](cpp/io/basic_ostringstream/str) function, as on [15].
