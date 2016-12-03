#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <functional>

auto main(void)-> int
{

    constexpr double prob = 0.8; //The probability it takes is the probability of returning true
    std::knuth_b rand_engine;
    std::bernoulli_distribution random_bool_generator(prob);
    auto random_bool = std::bind(random_bool_generator, rand_engine);
    // Now call random_bool() to get your random boolean with the
    // specified probability.
    //
    std::map<bool, int> hist;
    for(int n = 0; n < 10000; ++n)
        ++hist[random_bool()];

    for(auto p : hist)
    {
        std::cout << std::boolalpha << std::setw(5) << p.first
            << ' ' << std::string(p.second/500, '*') << '\n';
    }
    return 0;
}
