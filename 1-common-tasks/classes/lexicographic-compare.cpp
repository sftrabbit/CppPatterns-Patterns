// Lexicographic-compare
// C++11

#include <tuple>

class foo
{
	public:
		foo(int n_, char c_, double d_)
			: n{n_}, c{c_}, d{d_}
		{}

		friend bool operator<(const foo& lh, const foo& rh)
		{
			return	  std::tie(lh.n, lh.c, lh.d)
				< std::tie(rh.n, rh.c, rh.d);
		}
	private:
		int n;
		char c;
		double d;
};

// Implement compare of multiple members with std::tie
// 
// Getting an order relation right with 3 elements or more is
// tedious and easy to get wrong. Fortunately the standard
// library does it with tuples. The function template std::tie()
// creates a tuple with references to its arguments.
// 
// The class `foo`, on [6-22] has three member variables `n`, `c` and `d`
// declared on [19-21].
// 
// The less-than operator on [13-17] compares two `foo`s on the member
// `n` first, on the member `c` if the `n`s are equal, and finally on
// `d` if both the `n`s and `c`s are equal.
// 
// The formatting [14-15] to align the left hand and right hand
// arguments straight below each others makes it easier to spot
// mistakes as assymetries.
// 
// It is not necessary to declare the less-than operator as a friend
// function [13], it can be implemented as a member function as well,
// but this is a common idiom.

int main()
{
	foo f1(1, 'a', 3.14);
	foo f2(1, 'b', 2.78);

	if (f1 < f2)
	{
		return 1;
	}
}
