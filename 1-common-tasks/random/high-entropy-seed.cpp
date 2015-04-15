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
// determines the initial state of the engine. By providing such
// an engine with a greater amount of unpredictable seed data, we can
// achieve higher quality random number generation.
// 
// On [7], we create a [`std::random_device`](cpp/numeric/random/random_device)
// as a source of non-deterministic random numbers (if such a source
// is available). On [8], we initialise a [`std::seed_seq`](cpp/numeric/random/seed_seq)
// with several initial seeds produced by the `std::random_device`.
// On [10], we create a random number engine, seeding it with this
// `std::seed_seq`. This provides the random number engine with
// a new sequence of seeds that are unbiased and evenly distributed,
// even if the initial seeds were not. Providing more initial seeds
// increases the unpredictability of the engine.
// 
// While a `std::seed_seq` can be used to initialize multiple random
// number engines, bear in mind that a particular `std::seed_seq` will
// produce the same sequence of seeds each time it is used. We may,
// however, use a `std::seed_seq` to generate individual evenly
// distributed seeds for a large number of random number engines.
