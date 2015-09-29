// Reverse by Predicate
// c++11, c++14

#include <algorithm>

template <typename I, typename P>
void reverse_by_predicate(I begin, I end, P pred)
    //requires BidirectionalIterator<I> && Predicate<P, ValueType<I>>
{
    while (begin != end) {
        end = std::rotate(begin, std::find_if(begin, end, pred), end);
        if (begin == end) { return; }
        end = std::rotate(begin, std::find_if_not(begin, end, pred), end);
    }
}

// Reverse sub-sequences of some larger sequence.
//
// Useful when elements relate to each other in more complex ways than just
// their position in a range.  In the attached example, we reverse the words in
// a sentence by rotating blocks of "spaces" and "non-spaces" to the end of our
// range.  `std::rotate` returns the new position of what used to be in
// `begin`, which in our case was the start of our block.
//
// Thus by setting our `end` to this return value, we remove it from the blocks
// of text left to reverse.  Finally, we know that the next block of text we
// are to reverse will be the logical negation (`if -> if_not, if_not -> if`)
// of our previous search; hence the alternating rotation points.
//
// In more mathematical terms:
//
//   * Let `H` be longest _"block"_ of values with consistent predicate
//   evaluations.
//   * Let `T` be the rest of the values.
//
//   * Then `reverse(H + T) = reverse(T) + H`; and `T` can be broken up into
//   its own `H + T` pair.
//
//
// *Note*:  This can become more flexible if we allow our predicate to return
// any value, and split on non-equal evaluations.  This is left as an exercise
// for the reader!
//

#include <algorithm>
#include <iostream>
#include <string>

template <typename I, typename P>
void reverse_by_predicate(I begin, I end, P pred)
    //requires BidirectionalIterator<I> && Predicate<P, ValueType<I>>
{
    while (begin != end) {
        end = std::rotate(begin, std::find_if(begin, end, pred), end);
        if (begin == end) { return; }
        end = std::rotate(begin, std::find_if_not(begin, end, pred), end);
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
