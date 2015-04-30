// Erase-Remove idiom
// C++11

#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v {1,2,3,4,2,5,2,6};
	auto it = std::remove(std::begin(v), std::end(v), 2);
	v.erase(it, std::end(v)); 
	// now v is {1,3,4,5,6}	
	
	// remove all even numebers
	v.erase( std::remove_if( std::begin(v), std::end(v), [](int i) { return i%2 == 0; } ), std::end(v) ); 
	// now v is {1,3,5}
}

// Remove elements that satisfy a certain condition from a standard container.
// 
// On [9], we create a [`std::vector`](cpp/container/vector) as an example
// container and initialize it with int values.
// 
// On [10], we "remove" all the occurrences of the element 2,
// using the algorithm [`std::remove`](cpp/algorithm/remove) which actually shifts 
// (by means of move assignment) the elements in the range in such a way that 
// the elements that are not to be removed appear in the beginning of the range.
// This algorithm returns a past-the-end iterator for the new end of the range.
//
// On [11] we apply the second part of the idiom, by using vector's member function
// [`erase`](cpp/container/vector/erase) which really removes the elements in the range.
// 
// Generally this idiom is applied on a single line, as shown on line [15]. Here in particular,
// we used [`std::remove_if`](cpp/algorithm/remove) which "removes" all elements for which 
// a provided predicate returns true. We simply removed all the even values.
