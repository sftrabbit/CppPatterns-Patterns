// Roll a die
// C++11

#include <random>

int main()
{
	std::random_device random_device;
	std::mt19937 random_engine{random_device()};
	std::uniform_int_distribution<int> die_distribution{1, 6};
	
	int die_roll = die_distribution(random_engine);
}

// Generate a random integer according to a uniform distribution.
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
// [`std::uniform_int_distribution`](cpp/numeric/random/uniform_int_distribution)
// representing a uniform random distribution of integers from 1 to 6
// inclusive. That is, each value from 1 to 6 has an equal chance of
// occurring.
// 
// Finally, we generate a random number from the random engine,
// distributed according to the uniform integer distribution ([12]).
// This gives us a random integer from 1 to 6, as though we had rolled
// a 6-sided die.
// 
// To generate further random numbers, simply call
// `die_distribution(random_engine)` again.
