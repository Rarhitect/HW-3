#include <iostream>
#include <chrono>
#include <set>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <iomanip>

class Time_check
 {
 public:
     using steady_clock_type = std::chrono::steady_clock;
     using time_point_type = steady_clock_type::time_point;
     
     Time_check() : the_begin(steady_clock_type::now()), the_duration(0) {}
     ~Time_check()
     {
         auto end = steady_clock_type::now();
     }
     
     void stop()
     {
         auto end = steady_clock_type::now();
         auto duration = std::chrono::duration_cast <std::chrono::microseconds> (end - the_begin).count();
         the_duration += duration;
     }

      void start()
     {
         the_begin = steady_clock_type::now();
     }

      auto time()
     {
         auto end = steady_clock_type::now();
         auto duration = std::chrono::duration_cast <std::chrono::nanoseconds> (end - the_begin).count();
         return duration;
     }

  private:
     time_point_type the_begin;
     long long the_duration;
 };

int main()
{
    const auto N = 1000000;
    
    std::set<int> s;
    std::vector<int> v;
    std::array<int, N> a;
    
    Time_check timer_1;
    
    for (auto i = 0; i < N; ++i)
    {
        s.insert(i + 1);
    }
    
    auto test_1 = timer_1.time();
    
    std::cout << "The test with set-container is: " << test_1 << " ns" << std::endl;
    
    Time_check timer_2;
    
    for (auto i = N; i > 0; --i)
    {
        v.push_back(i+1);
    }
    std::sort(v.begin(), v.end());
    
    auto test_2 = timer_2.time();
    
    std::cout << "The test with vector-container is: " << test_2 << " ns" << std::endl;
    
    Time_check timer_3;
    
    for (auto i = N; i > 0; --i)
    {
        a[N - i] = i + 1;
    }
    std::sort(v.begin(), v.end());

    auto test_3 = timer_3.time();
    
    std::cout << "The test with array-container is: " << test_3 << " ns" << std::endl;
    
    std::vector<long long> results{test_1, test_2, test_3};
    std::sort(results.begin(), results.end());
    if (results[0] == test_1)
    {
        std::cout << "The best is set with " << test_1 << " nanoseconds! Congrats :)" << std::endl;
    }
    else if (results[0] == test_2)
    {
        std::cout << "The best is vector with " << test_2 << " nanoseconds! Congrats :)" << std::endl;
    }
    else if (results[0] == test_3)
    {
        std::cout << "The best is array with " << test_3 << " nanoseconds! Congrats :)" << std::endl;
    }
    
    return 0;
}
