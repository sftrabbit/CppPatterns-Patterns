// Check existence of a key
// C++11

#include <map>
#include <string>

int main()
{
	std::map<std::string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}};
	
	if (m.count("b"))
	{
		// We know "b" is in m
	}
}

// Check if a particular key is in an associative container.
// 
// On [9], we create a [`std::map`](cpp/container/map) as an example
// associative container and initialize it with key-value pairs.
// 
// On [11], we count the number of occurrences of the key `"b"` in `m`
// by using the member function [`count`](cpp/container/map/count).
// If `"b"` is in `m`, `count` will return 1; otherwise it will return
// 0.
//
// Note: in C++14, an instance of the searched key will not be created
// if the container's comparator is
// [transparent](http://stackoverflow.com/q/20317413/150634) and
// supports the appropriate comparison without conversions.
