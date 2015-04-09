// Optional arguments
// Experimental

#include <experimental/optional>

using std::experimental::optional;
using std::experimental::nullopt;

void foo(int i,
         optional<double> f,
         optional<bool> b)
{ }

int main()
{
	foo(5, 1.0, true);
	foo(5, nullopt, true);
	foo(5, 1.0, nullopt);
	foo(5, nullopt, nullopt);
}

// Allow argument values to be omitted when calling a function.
// 
// **Note**: This sample uses experimental entities from the Library
// Fundamentals TS that demonstrate likely upcoming features in C++
// but should not be used in production code.
// 
// The function `foo`, on [9-12], takes three arguments, two of which
// have type
// [`std::experimental::optional`](cpp/experimental/optional) (from
// the Library Fundamentals TS). This allows the value of those
// arguments to be omitted, as shown on [17-19], where
// [`std::experimental::nullopt`](cpp/experimental/optional/nullopt)
// represents no value.
// 
// This approach is more expressive than using pointers and `nullptr`.
// A related technique is the use of default arguments, which allow
// arguments to be omitted entirely, but only from the end of the
// argument list.
// 
// If you are constructing an object with a complex combinatorial set
// of optional arguments, consider using the
// [builder pattern](/patterns/builder.html).
// 
// **Note**: `std::experimental::optional` and
// `std::experimental::nullopt` are part of the Library Fundamentals
// Technical Specification, which provides experimental features that
// may soon be introduced to the C++ standard. They should not be used
// in production code.
