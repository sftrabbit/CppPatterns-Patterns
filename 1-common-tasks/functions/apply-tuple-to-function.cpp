// Apply tuple to a function
// C++14

#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>

template<typename F, typename Tuple, size_t ...S >
decltype(auto) apply_tuple_impl(F&& fn, Tuple&& t, std::index_sequence<S...>)
{
	return std::forward<F>(fn)(std::get<S>(std::forward<Tuple>(t))...);
}

template<typename F, typename Tuple>
decltype(auto) apply_from_tuple(F&& fn, Tuple&& t)
{
	std::size_t constexpr tSize
		= std::tuple_size<typename std::remove_reference<Tuple>::type>::value;

	return apply_tuple_impl(std::forward<F>(fn),
	                        std::forward<Tuple>(t),
	                        std::make_index_sequence<tSize>());
}

int do_sum(int a, int b) 
{
	return a + b;
}

int main()
{
	int sum = apply_from_tuple(do_sum, std::make_tuple(10, 20));
}

// Unpack a tuple as the arguments of a function.
// 
// The `apply_from_tuple` function template on [15-24] returns the
// result of applying the function `fn` to the values stored in the
// [`std::tuple`](cpp/utility/tuple) `t`. On [18-19], we store the
// size of `t` in `tSize`, which is declared `constexpr` so that
// it can be evaluated at compile-time. On [21-23], we call
// `apply_tuple_impl` passing `t`, `fn` and an 
// [`std::index_sequence`](cpp/utility/integer_sequence) 
// which carries a parameter pack containing a sequence of integers
// from `0` to `tSize - 1`.
// 
// The `apply_tuple_impl` function template on [9-13] returns the
// result of applying the function `fn` using event element of the
// tuple `t` as arguments (on [12]). To do this, we expand the
// parameter pack carried by the `std::index_sequence` and apply
// [`std::get`](cpp/utility/tuple/get) to the tuple for each
// integer in the sequence. This way, all the elements of `t` are
// expanded and passed to the function.
// 
// **Note**: a [`std::apply`](cpp/experimental/apply) function has
// been proposed as part of the Library Fundamentals TS for future
// standardization.
