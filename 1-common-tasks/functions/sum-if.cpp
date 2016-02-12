// Lambda functions
// C++11

#include <vector>

using std::vector;

template <typename T, typename P>
T sum_if(const vector<T>& vec, P pred) {
  T r = T();
  for (const T& v : vec) {
    if (pred(v)) { r += v; }
  }
  return r;
}

double sum_values_above_t(const vector<double>& vec, double t) {
  return sum_if(vec, [t](const double& d) { return d > t; });
}

// Sum up values in a vector which satisfy a given predicate.
//
// Lambda functions are an easy way to create function objects. The
// expression `[t](const double& d) { return d > t; }` on [18]
// constructs a function object that is passed to the sum-if templated
// function.
//
// The opening `[...]` defines a _capture list_ of variables in the
// current scope that can then be used within the function. This is
// followed by the parameter list that is taken as input, and then by
// the body of the function. The return value in this case is inferred
// by the type of `d > t` (i.e. `bool`).

int main() {
  double r = sum_values_above_t({1.0, 2.0, 4.0}, 1.5);
}
