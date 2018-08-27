// Use RAII types

#include <map>
#include <memory>
#include <string>
#include <vector>

int main()
{
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::map<std::string, int> map = {{"Foo", 10}, {"Bar", 20}};
  std::string str = "Some text";
  std::unique_ptr<int> ptr1 = std::make_unique<int>(8);
  std::shared_ptr<int> ptr2 = std::make_shared<int>(16);
}

// Avoid manual memory management to improve safety and reduce bugs
// and memory leaks.
//
// Every object created on [10-14] will internally manage some
// dynamically allocated memory (allocated with the `new` keyword).
// They are all, however, implemented such that they deallocate that
// memory when they are destroyed. This practice is known as RAII.
//
// The user of these classes does not need to perform manual memory
// management, reducing the risk of memory leaks and other bugs. In
// fact, the use of `new` and `delete` can be avoided entirely by
// using these RAII types.
//
// Likewise, it is good practice to ensure your own classes also
// implement the RAII idiom with the
// [rule of five](/patterns/rule-of-five.html)
// or [rule of zero](/patterns/rule-of-zero.html).
