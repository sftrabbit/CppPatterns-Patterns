// Pass array arguments

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

// Pass fixed-size arrays to a function.
// 
// We define function `compile_time`, on [6-7], to have a parameter of
// type [`std::array`](cpp/container/array), which represents
// *compile-time* fixed-size arrays. [!14-16] demonstrate passing
// arrays of size 3 to this function.
// 
// On [9-10], we define function `run_time` to have a parameter of type
// [`std::experimental::dynarray`](cpp/container/dynarray), which
// represents *run-time* fixed-size arrays. [!18-20] demonstrate
// passing arrays of various sizes to this function.
// 
// Using these types avoids the traditional approach of passing a
// pointer and array size separately, more clearly expressing intent
// and simplifying the function interface.
