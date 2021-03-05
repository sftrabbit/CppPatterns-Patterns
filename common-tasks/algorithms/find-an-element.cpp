#include <iostream>
#include <algorithm>
#include <vector>

bool isEven(int x) {
	return x % 2 == 0;
}

// Find an element in range
//
// To show you different kinds of usage of find function, 
// we implemented extra two versions of it.
//
// On [41], we passed iterators of the vector and as third 
// argument we also passed which number we are searching. If 
// the number we are looking for is exist in the vector, 
// the function will return an iterator to the number. We 
// can derefecence it to get its value. If the numbers cannot
// be found, the function returns iterator that points the end 
// of the vector ie. `numbers.end()`.
//
// The following line [43] does pretty the same job except 
// with one detail. This function takes its third argument as
// predicate which lets us filter the element we want. In 
// the example, we declared a predicate to find an even number.
// Therefore, the function starts looking for `the first even number`
// and returns an iterator to the element. If there is no even number
// in the vector, the function returns `end iterator` like it did in
// normal find function.
// 
// The function on [45] works same as line [29]. However, this time
// the function finds the first elements that does not satisfy the
// predicate. In other words, it returns `the first element that is
// not even`. Same as before, if the function cannot find such an 
// element, it returns `end iterator`.


int main() {
	std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::vector<int>::iterator it1 = 
					std::find(begin(numbers), end(numbers), 5);

	std::vector<int>::iterator it2 = 
					std::find_if(begin(numbers), end(numbers) , isEven);

	std::vector<int>::iterator it3 = 
					std::find_if_not(begin(numbers), end(numbers), isEven);

	std::cout << *it1 << std::endl;

	std::cout << *it2 << std::endl;

	std::cout << *it3 << std::endl;

	return 0;
}