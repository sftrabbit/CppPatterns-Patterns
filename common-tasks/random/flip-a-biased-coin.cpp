// Flip a biased coin
// C++11

#include <random>

int main()
{
  std::random_device random_device;
  std::mt19937 random_engine{random_device()};
  std::bernoulli_distribution coin_distribution{0.25};

  bool outcome = coin_distribution(random_engine);
}

// Generate a random boolean value according to a bernoulli
// distribution.
//
// The [`std::random_device`](cpp/numeric/random/random_device) on [8]
// provides a source of uniform non-deterministic random numbers
// (where such a source is available). We use this to seed the
// Mersenne Twister random number engine,
// [`std::mt19937`](cpp/numeric/random/mersenne_twister_engine), on
// [9]. Consider [other random number
// engines](http://en.cppreference.com/w/cpp/numeric/random#Predefined_random_number_generators)
// for different properties.
//
// On [10], we create a
// [`std::bernoulli_distribution`](cpp/numeric/random/bernoulli_distribution)
// representing a bernoulli distribution with a success probability of
// `0.25`. This can be thought of as a biased coin that will land on
// heads only a quarter of the time.
//
// Finally, we generate a random number from the random engine,
// distributed according to the bernoulli distribution ([12]).
// This gives us a boolean value that will be `true` with `0.25`
// probability and `false` otherwise.
