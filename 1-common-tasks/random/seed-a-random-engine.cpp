// Seed with high entropy
// C++11

#include <random>

int main() {
	std::random_device r;
	std::seed_seq seed_seq{r(), r(), r(), r(), r(), r()};

	std::mt19937 engine{seed_seq};
}

// Seed a random number engine with high entropy.
//
// To get unpredictable results from random number engines, we must
// provide them with a source of entropy. To achieve greater quality
// random number generation with higher entropy, we can provide a
// random number engine with a sequence of seeds.
// 
// On [7], we create a [`std::random_device`](cpp/numeric/random/random_device)
// as a source of non-deterministic random numbers (if such a source
// is available). On [8], we initialise a [`std::seed_seq`](cpp/numeric/random/seed_seq)
// with several initial seeds produced by the `std::random_device`. This
// `std::seed_seq` generates a new sequence of seeds that are unbiased and
// evenly distributed, even if the initial seeds were not. On [10], we
// create a random number engine, seeding it with the `std::seed_seq`.
// A particular `std::seed_seq` will produce the same sequence of
// seeds each time it is used.
//
// A `std::seed_seq` can also be used to initialize a large number of
// random number engines, providing each with a random seed generated
// by the `std::seed_seq`.
