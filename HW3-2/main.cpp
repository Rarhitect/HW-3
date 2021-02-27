#include <iostream>
#include <vector>
#include <chrono>

std::size_t hash(double d)
{
    return (unsigned&) d;
}

float random_nums()
{
    auto a = static_cast<double>(rand());
    auto b = static_cast<double>(rand());
    auto c = static_cast<double>(rand());
    return a * b / c;
}

constexpr std::size_t N = 100000;

int main()
{
    std::vector<double> test_vec;
    for (auto i = 0; i < N; ++i)
    {
        test_vec.push_back(random_nums());
    }
    std::sort(test_vec.begin(), test_vec.end());
    auto summ = 0;
    for (auto &i: test_vec)
    {
        auto begin = std::chrono::system_clock::now();
        hash(i);
        auto end = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        summ += elapsed.count();
    }
    std::cout << "Average time of hashing is " << static_cast<double>(summ)/static_cast<double>(N) << " ns" << std::endl;
    std::cout << "It is kind of quick result i think" << std::endl;
    return 0;
}
