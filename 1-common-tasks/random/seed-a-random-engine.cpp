// Seeding A Random Number Engine Unpredictably
// C++11

#include <random>

int main() {
	std::random_device r;
	std::seed_seq seed_seq{r(), r(), r(), r(), r(), r()};

	std::mt19937 engine{seed_seq};
}

// Seed a random number engine unpredictably
//
// In order to get unpredictable results from a pseudo-random number generator
// we need a source of unpredictable seed data. On [7] we create a
// [`std::random_device`](cpp/numeric/random/random_device) for this purpose. On
// [8] we use a [`std::seed_seq`](cpp/numeric/random/seed_seq) to combine
// several values produced by `random_device` into a form suitable for seeding a
// pseudo-random number generator. The more unpredictable data that is fed into
// the `seed_seq`, the less predictable the results of the seeded engine will
// be. On [10] we create a random number engine using the `seed_seq` to seed the
// engine's initial state.
//
// A `seed_seq` can be used to initialize multiple random number engines;
// `seed_seq` will produce the same seed data each time it is used.
//
// **Note**: Not all implemenations provide a source of non-deterministic data.
// Check your implementation's documentation for `std::random_device`.
