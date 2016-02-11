// Implementation of STL's `std::next_permutation`
// c++11, c++14

#include <algorithm>
#include <iterator>

template <typename I>
    //requires BidirectionalIterator<I> && LessThanComparable<ValueType<I>>
bool my_next_permutation(I begin, I end)
{
    const auto rbeg = std::make_reverse_iterator(end);
    const auto rend = std::make_reverse_iterator(begin);
    auto pivot = std::is_sorted_until(rbeg, rend);
    bool had_greater_permutation{false};
    if (pivot != rend) {
        std::iter_swap(pivot, std::upper_bound(rbeg, pivot, *pivot));
        had_greater_permutation = true;
    }
    std::reverse(rbeg, pivot);
    return had_greater_permutation;
}

// This is already implemented in the STL, but we can actually build it through
// other STL algorithms.  The algorithm's steps are as follows:  
// ![flow chart of algorithm][1]  
// *Borrowed from [http://www.nayuki.io/][2]*
//
// `std::prev_permutation` is left as an exercise.
//
// [1]: http://www.nayuki.io/res/next-lexicographical-permutation-algorithm/next-permutation-algorithm-thumb.png
// [2]: http://www.nayuki.io/page/next-lexicographical-permutation-algorithm
