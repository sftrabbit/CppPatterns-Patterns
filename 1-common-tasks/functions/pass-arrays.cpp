// Pass arrays
// C++11, Experimental

#include <array>
#include <experimental/dynarray>

void compile_time(std::array<int, 3> arr)
{ }

void run_time(std::experimental::dynarray<int> arr)
{ }

int main()
{
	std::array<int, 3> arr = {4, 8, 15};
	compile_time(arr);
	compile_time({16, 23, 42});

	std::experimental::dynarray<int> dynarr = {1, 2, 3};
	run_time(dynarr);
	run_time({1, 2, 3, 4, 5});
}

// Pass fixed-size arrays to and from functions.
// 
// Built-in array types are not copyable, so cannot be passed to and
// from functions by value. The traditional approach is to pass both a
// pointer to an array's first element and the size of the array.
// However, C++ provides class types that represent copyable
// fixed-size arrays.
// 
// We define the function `compile_time`, on [7-8], to have a
// parameter of type [`std::array`](cpp/container/array), which represents
// *compile-time* fixed-size arrays. This means that the size must be
// known at compile time. A template may be used to instantiate
// functions for different `std::array` sizes. [!15-17] demonstrate
// passing arrays of size 3 to this function.
// 
// On [10-11], we define function `run_time` to have a parameter of type
// [`std::experimental::dynarray`](cpp/container/dynarray), which
// represents *run-time* fixed-size arrays. This type can be created with
// any size at run time, but cannot change size once created. [!19-21]
// demonstrate passing arrays of various sizes to this function.
// 
// **Note**: `std::experimental::dynarray` is part of the Arrays
// Technical Specification, which provides experimental features that
// may soon be introduced to the C++ standard. It should not be used
// in production code.
