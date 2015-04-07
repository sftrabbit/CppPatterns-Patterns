// Pass arrays

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
// **Note**: This sample uses experimental entities from the Library
// Fundamentals TS that demonstrate likely upcoming features in C++
// but should not be used in production code.
// 
// C++ arrays are not copyable, so cannot be passed to and from
// functions by value. The traditional approach is to pass both a
// pointer to an array's first element and the size of the array.
// However, C++ provides class types that represent copyable
// fixed-size arrays.
// 
// We define the function `compile_time`, on [6-7], to have a
// parameter of type [`std::array`](cpp/container/array), which represents
// *compile-time* fixed-size arrays. This means that the size must be
// known at compile time. A template may be used to instantiate
// functions for different `std::array` sizes. [!14-16] demonstrate
// passing arrays of size 3 to this function.
// 
// On [9-10], we define function `run_time` to have a parameter of type
// [`std::experimental::dynarray`](cpp/container/dynarray), which
// represents *run-time* fixed-size arrays. This type can be created with
// any size at run time, but cannot change size once created. [!18-20]
// demonstrate passing arrays of various sizes to this function.
