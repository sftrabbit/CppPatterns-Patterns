// Read binary file

#include <array>
#include <cstdio>
#include <deque>
#include <fstream>

int main()
{
	using std::begin;
	using std::end;
	
	std::ifstream file{"file.dat", std::ios_base::in | std::ios_base::binary};
	if (file)
	{
		std::deque<unsigned char> buffer{};
		
		std::array<unsigned char, BUFSIZ> chunk{};
		
		while (file.read(reinterpret_cast<char*>(chunk.data()), chunk.size()) ||
		       file.gcount())
		{
			buffer.insert(end(buffer), begin(chunk), begin(chunk) + file.gcount());
		}
	}
}

// Read an entire binary file into a byte array without seeking.
// 
// We have two basic options for reading the contents of a file into a
// variable in memory: we can try to read bit-by-bit growing our
// memory buffer as we read, or we can try to determine the size then
// allocate the entire memory buffer at once and do one giant read
// directly into it. Which technique we use depends on numerous factors,
// such as the size of the data, how fast/slow the device we are reading
// from is, and whether or not we can make multiple read passes (we
// could not read input from a network stream more than once, for
// example). This sample illustrates the first option.
// 
// Before we begin, we use a pair of `using` directives on [10-11] to
// bring `std::begin` and `std::end` into scope. We will be using those
// shortly.
// 
// First we open an input file stream and confirm it opened successfully
// on [13-14]. Note that we open the stream in binary mode.
// 
// On [16] we prepare the buffer we will be reading the data into. We
// could use any container type (or even custom class types), but
// [`std::deque`](cpp/container/deque) is uniquely suited for this task.
// The reason is that `std::deque` is *almost* a `std::vector` - it is
// just about as efficient as a vector, both in terms of memory usage
// and speed, and it allows random access to the contents - except
// instead of holding its contents in a single contiguous block of
// memory, `std::deque` uses multiple blocks. When a 100 kiB
// `std::vector` has to grow, it has to allocate an entirely new block
// of memory *larger* than 100 kiB - usually double, so 200 kiB, which
// means that a total of 300 kiB is being used - then copy all 100 kiB
// of data from the old block to the new one, then delete the old block.
// Meanwhile, when a 100 kiB `std::deque` has to grow, it merely adds a
// new block and continues - this requires far less memory, and nothing
// has to copied.
// 
// In addition to our buffer, we prepare an array on [18] to act as a
// temporary buffer to hold each chunk as we read the file's data in
// chunk by chunk. We need to choose a reasonable size for the chunk
// buffer - too small and we're doing too many reads, too large and
// we're wasting memory. [`BUFSIZ`](cpp/io/c) is a reasonable default.
// 
// Now that our buffers are read, we begin the read loop ([20-25]). The
// read loop is a `while` loop with a compound test that can be read
// like this: "While we successfully read a whole chunk's worth of data
// ([20]) *OR* we *didn't* read a whole chunk but we did read *some*
// data ([21]) - that is, we read *part* of a chunk - insert everything
// we read at the end of the buffer ([23])". (Because
// [`read()`](cpp/io/basic_istream/read) expects to write to a
// character (`char`) buffer, we must use a `reinterpret_cast` to write
// to a byte (`unsigned char`) buffer.) The loop will continue reading
// chunks (or parts of chunks) until either there is an error or the end
// of the file is reached - you can use the stream's
// [`eof()`](cpp/io/basic_ios/eof) or [`fail()`](cpp/io/basic_ios/fail)
// function to determine which happened.
// 
// If the loop completed successfully, `buffer` will contain the entire
// contents of the binary file.
// 
// We could use this technique to read text data into a string, too
// (by not opening the file in binary mode). However, [there is
// a better way to read the contents of a file into a
// string](/common-tasks/read-text-file.html).
