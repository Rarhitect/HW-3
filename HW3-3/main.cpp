#include <iostream>
#include <string>
#include <random>
#include <set>

#include <boost/functional/hash.hpp>

std::set < std::string > make_random_words(std::size_t N, std::size_t length = 10)
{
    std::uniform_int_distribution <> letter(97, 122);
    std::default_random_engine e(static_cast < std::size_t > (
        std::chrono::system_clock::now().time_since_epoch().count()));

    std::set < std::string > words;

    for (std::string s(length, '_'); std::size(words) < N; words.insert(s))
        for (auto & c : s)
            c = letter(e);

    return words;
}

constexpr std::size_t size = 10000000;

int main()
{
    unsigned int collision_counter = 0;
    std::set < std::string > words = make_random_words(size);
    
    std::set < int > numerics;
    for (auto i = 0; i < size; ++i)
    {
        numerics.insert(rand());
    }
    
    std::set < std::size_t > word_hashes;
    std::set < std::size_t > numeric_hashes;
    for (auto i: words)
    {
        if (word_hashes.count(boost::hash_value(i)) == 0)
        {
            word_hashes.insert(boost::hash_value(i));
        }
        else
        {
            ++collision_counter;
        }
    }
    for (auto i: numerics)
    {
        if (numeric_hashes.count(boost::hash_value(i)) == 0)
        {
            numeric_hashes.insert(boost::hash_value(i));
        }
        else
        {
            ++collision_counter;
        }
    }
    
    std::cout << "We got " << collision_counter << " collisions" << std::endl;
    
    return 0;
}
