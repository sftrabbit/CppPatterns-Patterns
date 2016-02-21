// Read binary stream

#include <array>
#include <cstdio> // only for BUFSIZ
#include <deque>
#include <fstream>
#include <limits>
#include <vector>

std::vector<unsigned char> read_binary_stream1(std::istream& in)
{
	std::istream::pos_type start = in.tellg();
	in.ignore(std::numeric_limits<std::streamsize>::max());
	
	std::vector<unsigned char> buffer{};
	buffer.resize(in.gcount());
	
	in.seekg(start);
	in.read(reinterpret_cast<char*>(buffer.data()), buffer.size());
	
	return buffer;
}

std::deque<unsigned char> read_binary_stream2(std::istream& in)
{
	using std::begin;
	using std::end;
	
	std::deque<unsigned char> buffer{};
	
	std::array<unsigned char, BUFSIZ> chunk{};
	while (in.read(reinterpret_cast<char*>(chunk.data()), chunk.size()) ||
		     in.gcount())
	{
		buffer.insert(end(buffer), begin(chunk), begin(chunk) + in.gcount());
	}
	
	return buffer;
}

// Read the entire contents of a binary stream into a buffer.
// 
// We have two basic options for reading the contents of a stream into a
// variable in memory: We can try to determine the size then allocate
// the entire memory buffer at once and do one giant read directly into
// it (as in `read_binary_stream1()` on [10-22]), or we can try to read
// piece-by-piece growing our memory buffer as we read (as in
// `read_binary_stream2()` on [24-39]). Which technique we use depends on
// numerous factors, such as the size of the data, how fast/slow the
// device we are reading  from is, and whether or not the input stream
// is seekable (we could not seek back and forth arbitrarily on a
// network stream, for example).
// 
// In method 1, first we save the current location in the stream on
// [12]. This is so we can return to it after determining the size of
// stream
// 
// Then we skip right to the end using the stream's
// [`ignore()`](cpp/io/basic_istream/ignore) function on [13]. It is
// important that we use the `ignore()` method rather than the
// `seekg(0, std::ios_base::end)` method, because the latter does not
// work reliably on all platforms for technical reasons.
// 
// Next we create the buffer, and resize it to fit the entire stream on
// [15-16]. Note that the buffer must be a contiguous container type,
// like `std::vector` or `std::array` but not `std::list` or
// `std::deque`, because later we will be using `read()`, which writes
// to a contiguous memory block. The stream's
// [`gcount()`](cpp/io/basic_istream/gcount) function tells us the
// number of bytes read in the last input operation, and `ignore()` is
// an input operation that we just used to "read" the entire stream.
// This ensures the buffer is now large enough to hold the entire
// stream.
// 
// Then we seek back to the location we started at on [18], and do the
// giant read of the whole stream into the buffer on [19]. Note that we
// must use a `reinterpret_cast`, because `read()` expects a character
// (`char`) buffer (IOStreams are text-based by default), while we are
// reading bytes (`unsigned char`s). This cast is safe, because `char`
// and `unsigned char` are defined to be the same type, except
// (possibly) for signedness, which doesn't matter in this context.
// 
// If all of this was successful, `buffer` now contains the entire
// contents of the stream.
// 
// In method 2, before we do anything, we use `using` declarations on
// [26-27] to bring `std::begin()` and `std::end()` into scope. We
// will be using them shortly.
// 
// On [29], we prepare the buffer we will be writing the stream's data
// into. Unlike with the previous method, which required a contiguous
// container type, we can use any container type - even custom
// user-defined containers. However, [`std::deque`](cpp/container/deque)
// is uniquely suited for this task. The reason is that `std::deque` is
// *almost* a `std::vector` - it is just about as efficient as a vector,
// both in terms of memory usage and speed, and it allows random access
// to the contents. The primary difference is that instead of holding
// its contents in a single contiguous block of memory, `std::deque`
// uses multiple blocks. When a 100 kiB `std::vector` has to grow, it
// has to allocate an entirely new block of memory *larger* than 100 kiB
// (usually double, so 200 kiB, which means that a total of 300 kiB is
// being used), then copy all 100 kiB of data from the old block to the
// new one, then delete the old block. Meanwhile, when a 100 kiB
// `std::deque` has to grow, it merely adds a new block to its internal
// list, and continues - this requires far less memory, and nothing has
// to copied. Thus, `std::deque` is a better choice for a container we
// know will be growing piece-by-piece.
// 
// In addition to our buffer, we prepare an array on [31] to act as a
// temporary buffer to hold each chunk as we read the stream's data in
// chunk by chunk. We need to choose a reasonable size for the chunk
// buffer - too small and we're doing too many reads, too large and
// we're wasting memory. [`BUFSIZ`](cpp/io/c) is a reasonable default.
// 
// Now that our buffers are ready, we begin the read loop ([32-36]). The
// read loop is a `while` loop with a compound test that can be read
// like this: "While we successfully read a whole chunk's worth of data
// ([32]) *OR* we *didn't* read a whole chunk but we did read *some*
// data ([33]) - that is, we read *part* of a chunk - insert everything
// we read at the end of the buffer ([35])". Once again, because
// [`read()`](cpp/io/basic_istream/read) expects to write to a
// character (`char`) buffer, we must use a `reinterpret_cast` to write
// to a byte (`unsigned char`) buffer. The loop will continue reading
// chunks (or parts of chunks) until either there is an error or the end
// of the stream is reached - you can use the stream's
// [`eof()`](cpp/io/basic_ios/eof) or [`fail()`](cpp/io/basic_ios/fail)
// function to determine which happened.
// 
// If the loop completed successfully, `buffer` will contain the entire
// contents of the stream.
// 
// Note that we could use either of these methods to read text data into
// a string (like `std::vector`, `std::string` is a contiguous
// container type). However, [there is a better way to read the contents
// of a stream into a string](/common-tasks/read-text-stream.html).

int main()
{
	std::ifstream file1{"file.dat", std::ios_base::in | std::ios_base::binary};
	std::vector<unsigned char> data1 = read_binary_stream1(file1);
	
	std::ifstream file2{"file.dat", std::ios_base::in | std::ios_base::binary};
	std::deque<unsigned char> data2 = read_binary_stream2(file2);
}
