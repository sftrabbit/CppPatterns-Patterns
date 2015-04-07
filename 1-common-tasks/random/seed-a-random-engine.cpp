// Seeding A Random Number Engine

#include <random> // for std::mt19937, std::random_device, and std::seed_seq

void seed1() {
  std::random_device random_device;
  std::mt19937 engine{random_device()};

  engine.seed(random_device());
}

#include <chrono>   // for std::chrono
#include <cstdint>  // for std::uint_least32_t
#include <iostream> // for std::cout and std::cin

void seed2() {

  std::uint_least32_t time =
      std::chrono::system_clock::now().time_since_epoch().count();
  std::uint_least32_t other_data;
  std::cout << "Enter a random number: ";
  std::cin >> other_data;
  std::random_device rd;
  std::seed_seq seed{1u, 2u, 3u, time, other_data, rd(), rd()};

  std::mt19937 engine{seed};

  engine.seed(seed);
}

#include <algorithm> // for std::generate
#include <utility>   // for std::ref

struct random_seed_seq {
  std::random_device rd;

  template <typename RandomAccessIt>
  void generate(RandomAccessIt rb, RandomAccessIt re) {
    std::generate(rb, re, std::ref(rd));
  }
};

void seed4() {
  random_seed_seq seed;
  std::mt19937 engine{seed};
}

// Seed a random number engine
//
// On [7] we seed a
// [`std::mt19937`](cpp/numeric/random/mersenne_twister_engine) engine
// using a single value from a
// [`std::random_device`](cpp/numeric/random/random_device).
//
// All standard engines have a convienence constructor for seeding
// with a single value. This may be fine for many usages, however this
// can limit the potential output of an engine. The vast majority of
// the output a `mt19937` engine is capable of will never be produced
// by the engine on [5].
//
// [9] demonstrates using an engine's `seed()` member function.
// Standard engines support taking seeds either during construction or
// in a seperate call to `seed()` taking the same arguments.
//
// Standard random number engines support an interface capable of
// accepting an arbitrary amount of seed data in order to increase the
// possibilities. This is done through an engine's template
// constructor or template function seed() taking an object conforming
// to the [`SeedSequence`](cpp/concept/SeedSequence) concept.
// [`std::seed_seq`](cpp/numeric/random/seed_seq) provides a default
// implementation of this concept which takes any amount of data,
// performs a warm-up sequence on it, and then provides the data to
// the engine through the Seed Sequence interface. [24] demonstrates
// constructing a `std::seed_seq` with several sources of data and
// [26] and [28] demonstrate using the `std::seed_seq`.
//
// If you wish to completely randomize an engine's state then the
// warm-up performed by `std::seed_seq` is unnecessary. You can
// instead provide your own implementation which doesn't do the
// unnecessary work and which makes it easy to provide exactly the
// amount of seed data requested by any given engine.
//
// [34] demonstrates an example of this, however the shown
// `random_seed_seq` doesn't fully conform to the Seed Sequence
// requirements and so this example is, strictly speaking,
// 'non-portable'. All current major C++11 implementations support
// this usage, however. A portable implementation requires fully
// implementing the [`SeedSequence`](cpp/concept/SeedSequence)
// concept.
