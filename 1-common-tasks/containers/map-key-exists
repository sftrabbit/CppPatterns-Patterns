// Check if a certain key is in a std::map
// C++11

#include <map>
#include <string>

int main()
{
  std::map<string, int> m = { {"a", 1}, {"b", 2}, {"c", 3} };
  
  if (m.count("b"))
  {
     // we know "b" is in m
  }
}

// Check if a certain key is in a std::map.
// 
// On [8], we create a [`std::map`](cpp/container/map)
// and initialise it with key-value pairs.
// 
// On [10], we count the number of occurrences of the key "b" in m
// by using the memeber function [`count`](cpp/container/map/count).
// If "b" is in m, count will return 1, 0 otherwise.
//  
// Note: to reference the corresponding value don't use this idiom but
// consider [getting an element by key in std::map](/common-tasks/map-get-value-by-key.html)
//
// Note: in C++14 it's possible to do even better, without constructing an instance of the
// searched key. See [`count`](cpp/container/map/count) for more details.
