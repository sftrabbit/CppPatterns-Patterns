// Perfect forwarding

#include <iostream>
#include <string>
#include <utility>

static int pair_counter = 0;

template<typename T, typename U>
auto
make_pair_and_count(T&& t, U&& u)
{
   pair_counter++;
   return std::make_pair(std::forward<T>(t), std::forward<U>(u));
}

// Forwards an argument of a wrapping function to a wrapped function
// *as if* the wrapped function was called directly without the wrapper.
// 
// Perfect forwarding preserves argument's value category (rvalue/lvalue) and
// const/volatile modifiers. Perfect forwarding is done in two steps:
// receive a *forwarding reference* (also known as *universal reference*),
// then forward it using `std::forward`(cpp/utility/forward). 
// In our example `t` and `u` on [14] are forwarding references.
//
// [`std::make_pair`](cpp/utility/pair/make_pair) is itself 
// declared with forwarding references as arguments, so that you can
// *move-in* rvalues into a pair without any extra temporaries, and
// our wrapping function preserves this behavior.
//
// Perfect forwarding is often done with [variadic templates](cpp/language/parameter_pack) to wrap
// calls to functions with arbitrary number of arguments. For example,
// [`std::make_unique`](cpp/memory/unique_ptr/make_unique) and
// [`std::make_shared`](cpp/memory/shared_ptr/make_shared) are 
// perfect forwarding their arguments to the constructor of the 
// wrapped type.

int main()
{
   using namespace std;

   pair<int, int> p1{ make_pair_and_count(1, 2) };

   const string str("str");
   pair<int, string> p2{ make_pair_and_count(p1.first, str) };

   cout << pair_counter << " pairs were made";
}
