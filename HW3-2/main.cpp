#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::size_t hash(double d)
{
    return (unsigned&) d % 1001;
}

constexpr std::size_t N = 1000;

int main()
{
    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::vector<double> test_vec1;
    for (auto i = 0; i < N; ++i)
    {
        test_vec1.push_back(static_cast<double>(mersenne()));
    }
    std::sort(test_vec1.begin(), test_vec1.end());
    auto summ = 0;
    for (auto &i: test_vec1)
    {
        auto begin = std::chrono::system_clock::now();
        hash(i);
        auto end = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        summ += elapsed.count();
    }
    std::cout << "Average time of hashing is " << static_cast<double>(summ)/static_cast<double>(N) << " ns" << std::endl;
    std::cout << "It is kind of quick result i think" << std::endl;

    std::vector<double> test_vec2;
    for (auto i = 0; i < N; ++i)
    {
        test_vec2.push_back(static_cast<double>(mersenne()));
    }
    std::sort(test_vec2.begin(), test_vec2.end());

    std::cout << "Testing the uniformity....." << std::endl;
    auto number = 1;
    for(auto &i: test_vec2)
    {
        std::cout << number << ";" << hash(i) << std::endl;
        ++number;
    }

    return 0;
}

