// Choose a random element
// C++11

#include <random>
#include <vector>

int main()
{
  std::vector<int> v = {10, 15, 20, 25, 30};

  std::random_device random_device;
  std::mt19937 engine{random_device()};
  std::uniform_int_distribution<int> dist(0, v.size() - 1);

  int random_element = v[dist(engine)];
}

// Choose a random element from a container.
//
// On [9], we create a [`std::vector`](cpp/container/vector) from
// which we want to select a random element.
//
// We then effectively [roll a die](/patterns/roll-a-die.html)
// where the numbers on the die are the indices of elements in the
// container. That is, we seed the
// [`std::mt19937`](cpp/numeric/random/mersenne_twister_engine) on
// [11-12] and create a uniform random distribution of integers from
// `0` to `v.size() - 1` inclusive on [13]. This distribution will
// give us any integer in this range with equal probability.
//
// On [15], we call `dist(engine)` to generate the random index, and
// use this value to access an element from `v`.
