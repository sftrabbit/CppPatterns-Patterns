// Accumulate values from a range
// C++11

#include <deque>
#include <forward_list>
#include <numeric>
#include <vector>

template <typename Collection>
typename Collection::value_type
sum_numbers(Collection const& collection)
{
    using ReturnType = typename Collection::value_type;
    return std::accumulate(std::begin(collection), std::end(collection), static_cast<ReturnType>(0));
}

// Sums elements in a collection
//
// Here is the simplest usage of [`std::accumulate`](cpp/algorithm/accumulate):
// take a collection of numbers and calculate their cumulative sum.
//
// The template on [8] allows us to consider any collection of numbers, not
// necessarily a vector. The return type  is the same type of elements contained
// in the collection, so for example a collection of `double`s will calculate and
// return the sum in a `double`, while a collection of `int` will return an
// `int`.
//
// The third argument passed to [`std::accumulate`](cpp/algorithm/accumulate)
// corresponds to the initial value that will be used while _accumulating_. The
// type of this value will be the return type of the function. Thus, we
// make the return type explicit with the `static_cast` at the end of [14],
// because just writing 0 with no type will make the compiler treat it as `int`,
// and that will produce loss of precision when the numbers are of floating
// point type.
//
// To use [`std::accumulate`](cpp/algorithm/accumulate) you need to `#include`
// the `<numeric>` header.

int main()
{
    std::vector<int> int_vec = {-1, 0, 1, 2, 3, 4, 5, 6, -6};
    int int_sum = sum_numbers(int_vec); // 14

    std::forward_list<double> double_vec = {1.0, 2.1, 3.3, 4.4, 5.5};
    double double_sum = sum_numbers(double_vec); // 16.3

    std::deque<unsigned int> unsigned_vec = {0, 2, 4, 6};
    unsigned int unsigned_sum = sum_numbers(unsigned_vec); // 12
}
