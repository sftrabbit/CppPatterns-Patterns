// Read binary file

#include <array>
#include <cstdio> // only for BUFSIZ
#include <deque>
#include <fstream>
#include <limits>
#include <vector>

std::vector<unsigned char> read_binary_file1(std::string const& filename)
{
	std::ifstream file{filename, std::ios_base::in | std::ios_base::binary};
	
	file.ignore(std::numeric_limits<std::streamsize>::max());
	
	std::vector<unsigned char> buffer{};
	buffer.resize(file.gcount());
	
	file.seekg(0);
	file.read(reinterpret_cast<char*>(buffer.data()), buffer.size());
	
	return buffer;
}

std::deque<unsigned char> read_binary_file2(std::string const& filename)
{
	using std::begin;
	using std::end;
	
	std::ifstream file{filename, std::ios_base::in | std::ios_base::binary};
	
	std::deque<unsigned char> buffer{};
	
	std::array<unsigned char, BUFSIZ> chunk{};
	while (file.read(reinterpret_cast<char*>(chunk.data()), chunk.size()) ||
		     file.gcount())
	{
		buffer.insert(end(buffer), begin(chunk), begin(chunk) + file.gcount());
	}
	
	return buffer;
}

// Read an entire binary file into a byte array.
// 
// We have two basic options for reading the contents of a file into a
// variable in memory: We can try to determine the size then allocate
// the entire memory buffer at once and do one giant read directly into
// it (as in `read_binary_file1()` on [10-23]), or we can try to read
// piece-by-piece growing our memory buffer as we read (as in
// `read_binary_file2()` on [25-41]). Which technique we use depends on
// numerous factors, such as the size of the data, how fast/slow the
// device we are reading  from is, and whether or not we can make
// multiple read passes (we  could not read input from a network stream
// more than once, for example).
// 
// In method 1, first we open an input file stream on [12]. Note that we
// open the stream in binary mode.
// 
// Once the file is open, the first thing we do is skip right to the end
// using the stream's [`ignore()`](cpp/io/basic_istream/ignore)
// function on [14]. It is important that we use the `ignore()` method
// rather than the `seekg(0, std::ios_base::end)` method, because the
// latter does not work reliably on all platforms.
// 
// Next we create the buffer, and resize it to fit the entire file on
// [16-17]. Note that the buffer must be a contiguous container type,
// like `std::vector` or `std::array`, but not `std::list` or
// `std::deque` (because later we will be using `read()`, which writes
// to a contiguous memory block). The stream's
// [`gcount()`](cpp/io/basic_istream/gcount) function tells us the
// number of bytes read in the last input operation, and `ignore()` is
// an input operation that we just used to "read" the entire file. This
// ensures the buffer is now large enough to hold the entire file.
// 
// Then we seek back to the beginning of the file ([19]), and do the
// giant read of the whole file into the buffer on [20]. Note that we
// must use a `reinterpret_cast`, because `read()` expects a character
// (`char`) buffer (IOStreams are text-based by default), while we are
// reading bytes (`unsigned char`s). This cast is safe, because `char`
// and `unsigned char` are defined to be the same type, except
// (possibly) for signedness, which doesn't matter in this context.
// 
// If all of this was successful, `buffer` now contains the entire
// contents of the file.
// 
// In method 2, we again begin by opening a file input stream ([30]),
// but before that we use `using` declarations on [27-28] to bring
// `std::begin()` and `std::end()` into scope. We will be using them
// shortly.
// 
// After we open the file, we prepare the buffer we will be writing
// the file's data into on [32]. Unlike with the previous method (which
// required a contiguous container type), we can use any container type
// (even custom user-defined containers). However,
// [`std::deque`](cpp/container/deque) is uniquely suited for this task.
// The reason is that `std::deque` is *almost* a `std::vector` - it is
// just about as efficient as a vector, both in terms of memory usage
// and speed, and it allows random access to the contents. The primary
// difference is that instead of holding its contents in a single
// contiguous block of memory, `std::deque` uses multiple blocks. When a
// 100 kiB `std::vector` has to grow, it has to allocate an entirely new
// block of memory *larger* than 100 kiB (usually double, so 200 kiB,
// which means that a total of 300 kiB is being used), then copy all
// 100 kiB of data from the old block to the new one, then delete the
// old block. Meanwhile, when a 100 kiB `std::deque` has to grow, it
// merely adds a new block and continues - this requires far less
// memory, and nothing has to copied. Thus, `std::deque` is a better
// choice for a container we know will be growing piece-by-piece.
// 
// In addition to our buffer, we prepare an array on [34] to act as a
// temporary buffer to hold each chunk as we read the file's data in
// chunk by chunk. We need to choose a reasonable size for the chunk
// buffer - too small and we're doing too many reads, too large and
// we're wasting memory. [`BUFSIZ`](cpp/io/c) is a reasonable default.
// 
// Now that our buffers are ready, we begin the read loop ([35-39]). The
// read loop is a `while` loop with a compound test that can be read
// like this: "While we successfully read a whole chunk's worth of data
// ([35]) *OR* we *didn't* read a whole chunk but we did read *some*
// data ([36]) - that is, we read *part* of a chunk - insert everything
// we read at the end of the buffer ([38])". Once again, because
// [`read()`](cpp/io/basic_istream/read) expects to write to a
// character (`char`) buffer, we must use a `reinterpret_cast` to write
// to a byte (`unsigned char`) buffer. The loop will continue reading
// chunks (or parts of chunks) until either there is an error or the end
// of the file is reached - you can use the stream's
// [`eof()`](cpp/io/basic_ios/eof) or [`fail()`](cpp/io/basic_ios/fail)
// function to determine which happened.
// 
// If the loop completed successfully, `buffer` will contain the entire
// contents of the binary file.
// 
// Note that we could use either of these methods to read text data into
// a string (like `std::vector`, `std::string` is a contiguous
// container type). However, [there is a better way to read the contents
// of a file into a string](/common-tasks/read-text-file.html).

int main()
{
	std::vector<unsigned char> data1 = read_binary_file1("file.dat");
	std::deque<unsigned char> data2 = read_binary_file2("file.dat");
}
