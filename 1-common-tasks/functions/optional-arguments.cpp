// Optional arguments

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
// The function `foo`, on [8-11], takes three arguments, two of which
// have type
// [`std::experimental::optional`](cpp/experimental/optional) (from
// the Library Fundamentals TS). This allows the value of those
// arguments to be omitted, as shown on [16-18].
// 
// A related technique is the use of default arguments, which allow
// arguments to be omitted entirely, but only from the end of the
// argument list.
// 
// If you are constructing an object with a complex combinatorial set
// of optional arguments, consider using the
// [builder pattern](/patterns/creational/builder.html).
