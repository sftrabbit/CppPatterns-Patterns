//Counting occurrence of particular element in a Range of elements
//C++11

# include <iostream>
# include <algorithm>
# include <vector>

int main()
{
 std::vector<int> numbers = {1,2,3,5,6,3,4,1};
 int element_to_look_for = 3;
 std::cout<<"Number of times 3 occurs : "<<std::count(std::begin(numbers),std::end(numbers),element_to_look_for);
}

//Count occurrences of a particular element in a range of elements
//
// On [10] we create a [`std::vector`](cpp/container/vector) of `int` to store elements.
//
// On [12], we call the standard alrogithm
// [`std::count`](cpp/algorithm/count), which counts the occurrence of a particular element, (which in this
// case is 3, stored in the variable named `element_to_look_for` on [11]).
// We use [`std::begin`](cpp/iterator/begin) and
// [`std::end`](cpp/iterator/end) to get the begin and end iterators to specify range of the container
// To count elements which meet a certain condition, use [`std::count`](cpp/algorithm/count).
