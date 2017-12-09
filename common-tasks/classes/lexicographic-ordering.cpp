// Lexicographic ordering
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
      return std::tie(lh.n, lh.c, lh.d) <
             std::tie(rh.n, rh.c, rh.d);
    }
  private:
    int n;
    char c;
    double d;
};

// Implement a lexicographic ordering over class members.
//
// The class `foo`, on [6-22], has three member variables `n`, `c` and
// `d` declared on [19-21]. We wish to implement an ordering relation
// for `foo` where these members are compared lexicographically.
//
// Getting an ordering relation right with 3 elements or more is
// tedious and error-prone. Fortunately, the standard library
// provides a lexicographic ordering over
// [`std::tuple`](cpp/utility/tuple), which we can utilise.
//
// The less-than operator for `foo` defined on [13-17] compares the
// member `n` first, then `c` if the `n`s are equal, and finally the
// member `d` if both the `n`s and `c`s are equal. To achieve this,
// we use [`std::tie`](cpp/utility/tuple/tie) on [15] and [16] to
// create `std::tuple`s containing references to the members of
// the left operand and right operand respectively. The comparison
// of these `std::tuple`s provides a lexicographic ordering over
// these members.

int main()
{
  foo f1(1, 'a', 3.14);
  foo f2(1, 'b', 2.78);

  if (f1 < f2)
  {
    return 1;
  }
}
