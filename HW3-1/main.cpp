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
         auto duration = std::chrono::duration_cast <std::chrono::microseconds> (end - the_begin).count();
         return duration;
     }

  private:
     time_point_type the_begin;
     long long the_duration;
 };

int main()
{
    
    return 0;
}
