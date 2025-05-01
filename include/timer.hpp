#pragma once

#include <chrono>
#include <sstream>

using namespace std::chrono;
using clock_ = high_resolution_clock;

class Timer {
public:
  Timer(std::string &str) : str_(str) { start_ = clock_::now(); }
  ~Timer() {
    end_ = clock_::now();
    auto msec = duration_cast<milliseconds>(end_ - start_).count();
    std::stringstream ss;
    ss << msec << " ms";
    str_ = ss.str();
  }

private:
  std::string &str_;
  clock_::time_point start_, end_;
};
