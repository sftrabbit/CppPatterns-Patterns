// Unpredictable random numbers
// C++11

#include <random>

int main() {
  std::random_device r;
  std::seed_seq seed_seq{r(), r(), r(), r(), r(), r()};

  std::mt19937 engine{seed_seq};
}

// Seed a random number engine with greater unpredictability.
//
// A pseudo-random number engine is initialised with a seed, which
// determines the initial state of the engine. When seeding with
// a single 32 bit value (as is typically provided by
// [std::random_device](cpp/numeric/random/random_device)), the
// engine can be in one of only 2<sup>32</sup> states. By providing an
// an engine with a greater amount of random seed data, we increase
// the number of possible states and therefore the unpredicitability
// of the engine.
//
// On [7], we create a `std::random_device` as a source of
// non-deterministic random numbers (if such a source is available).
// On [8], we initialise a [`std::seed_seq`](cpp/numeric/random/seed_seq)
// with several initial seeds produced by the `std::random_device`.
// On [10], we seed a random number engine with this `std::seed_seq`,
// which provides the engine with a sequence of evenly
// distributed seeds with low bias (although [not
// bias-free](http://www.pcg-random.org/posts/cpp-seeding-surprises.html)).
// Providing more initial seeds will increase the unpredictability of
// the engine by increasing the number of possible seed sequences that
// might be generated.
//
// While a `std::seed_seq` can be used to initialize multiple random
// number engines, bear in mind that a particular `std::seed_seq` will
// produce the same sequence of seeds each time it is used.
//
// **Note**: An unpredictable random number engine is not necessarily
// cryptographically secure.
