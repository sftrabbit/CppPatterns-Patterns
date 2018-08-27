// Optional arguments
// C++17

#include <optional>

void foo(int i,
         std::optional<double> f,
         std::optional<bool> b)
{ }

int main()
{
  foo(5, 1.0, true);
  foo(5, std::nullopt, true);
  foo(5, 1.0, std::nullopt);
  foo(5, std::nullopt, std::nullopt);
}

// Allow argument values to be omitted when calling a function.
//
// The function `foo`, on [6-9], takes three arguments, two of which
// have type [`std::optional`](cpp/utility/optional) (from
// the Library Fundamentals TS). This allows the value of those
// arguments to be omitted, as shown on [13-16], where
// [`std::nullopt`](cpp/utility/optional/nullopt) represents no value.
//
// This approach is more expressive than using pointers and `nullptr`.
// A related technique is the use of default arguments, which allow
// arguments to be omitted entirely, but only from the end of the
// argument list.
//
// If you are constructing an object with a complex combinatorial set
// of optional arguments, consider using the
// [builder pattern](/patterns/builder.html).
