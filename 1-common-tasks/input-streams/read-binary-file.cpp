// Read binary file

#include <fstream>
#include <limits>
#include <vector>

int main()
{
  std::ifstream file{"file.dat", std::ios_base::in | std::ios_base::binary};
  if (file &&
      file.ignore(std::numeric_limits<std::streamsize>::max()))
  {
    std::streamsize size = file.gcount();
    file.seekg(0);
    
    std::vector<unsigned char> buffer{};
    buffer.resize(size);
    
    file.read(reinterpret_cast<char*>(buffer.data()), buffer.size());
  }
}

// Read an entire binary file into a byte array.
// 
// We have two basic options for reading the contents of a file into a
// variable in memory: we can try to read bit-by-bit growing our
// memory buffer as we read, or we can try to determine the size then
// allocate the entire memory buffer at once and do one giant read
// directly into it. Which technique we use depends on numerous factors,
// such as the size of the data, how fast/slow the device we are reading
// from is, and whether or not we can make multiple read passes (we
// could not read input from a network stream more than once, for
// example). This sample illustrates the second option.
// 
// First we open an input file stream on [9]. Note that we open the
// stream in binary mode.
// 
// On [10] we check to confirm the file opened successfully, then in a
// compound test (using the `&&` AND operator) we use the input stream's
// [`ignore()`](cpp/io/basic_istream/ignore) function on [11] and check
// the result to ensure there was no read error.
// 
// If the previous operations were successful, we are now at the end of
// the input file, and we can use the
// [`gcount()`](cpp/io/basic_istream/gcount) function ([13]) to
// determine the  number of bytes we ignored to get there - which is the
// size of the file's data. The reason we have to do it this way is
// because simply using seek functions to seek to the end of the file is
// unreliable. The end of the file is not always the same as the end of
// the file's data - some file systems put padding at the end of files
// for technical and performance reasons.
// 
// After getting the number of bytes in the file ([13]), we seek back
// to the beginning of the file on [14], and begin preparing the memory
// buffer we will be reading into.
// 
// We create a vector of bytes ([16-17]), and set its size to the number
// of bytes we determined on [13]. Then we use the stream's
// [`read()`](cpp/io/basic_istream/read) function to do a single giant
// read of all the file's data into the buffer ([19]). Because `read()`
// expects a character buffer while we wish to write to a byte buffer,
// we use a `reinterpret_cast` (which we know is safe, because `char`
// and `unsigned char` are always the same size).
// 
// Note that we could use this technique to read text data into a
// string, because like `std::vector` `std::string` is a contiguous
// container type (other containers like `std::list` and `std::deque`
// are not contiguous, so we could not use those). However, [there is
// a better way to read the contents of a file into a
// string](/common-tasks/read-text-file.html).
