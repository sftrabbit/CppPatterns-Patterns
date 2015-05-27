// Constrained Perfect forwarding
// C++11 C++14

#include <string>
#include <utility>

class foo
{
	public:
		template <
			typename T,
			typename = typename std::enable_if<
				std::is_constructible<std::string, T>::value
			>::type
		>
		foo(T&& t) : s(std::forward<T>(t)...) {}
	private:
		std::string s;
};

// Constraining
// [perfect forwarding](/common-tasks/templates/perfect-forwarding.html)
// to legal types only improves error messages when needed, without hampering
// versatility or performance.
//
// In this example, we want `foo` to be constructible with a string,
// be it a [`std::string`](cpp/string/basic_string), `char*` or or
// string literal, and initialize the member string in the most efficient
// way possible.
//
// Lines [12-14] is a variant of the
// [function template SFINAE](/common-tasks/function-template-sfinae.html)
// ensuring that the constructor [16] only exists for some types `T`.
// In this case line [13],
// [`std::is_constructible`](cpp/types/is_constructible) provides the
// enabling constraint that `T` must be a type from which a
// [`std::string`](cpp/string/basic_string) can be constructed.
//
// Removing lines [12-14] gives the same functionality for a correct program,
// but the constraint makes the compiler issue much better error messages
// in the case of type errors, referring to the non-existence of matching
// constructor for `foo` instead of mismatching constructors in
// [`std::string`](cpp/string/basic_string).

int main(int argc, char *argv[])
{
	foo obj1(std::string("a"));
	foo obj2("a");
	foo obj3(argv[0]);
	//  foo obj4(1);
}
