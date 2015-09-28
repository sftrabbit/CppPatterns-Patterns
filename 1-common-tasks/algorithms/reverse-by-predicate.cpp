//! C++14
#include <algorithm>
#include <iostream>
#include <string>

template <typename I, typename P>
void reverse_by_predicate(I begin, I end, P pred)
    //requires BidirectionalIterator<I> && Predicate<P, ValueType<I>>
{
    while (begin != end) {
        end = std::rotate(begin, std::find_if(begin + 1, end, pred), end);
        if (begin == end) { return; }
        end = std::rotate(begin, std::find_if_not(begin + 1, end, pred), end);
    }
}

int main()
{
    std::string str{ "mary had a little lamb whose fleece was white as snow" };
    std::cout << '"' << str << '"' << std::endl;
    reverse_by_predicate(str.begin(), str.end(), ::isspace);
    std::cout << '"' << str << '"' << std::endl;
    // `str` is now: "snow as white was fleece whose lamb little a had mary"
}
