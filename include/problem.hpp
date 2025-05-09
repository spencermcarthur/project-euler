#pragma once

#include <iostream>

#include "timer.hpp"

// CRTP base class for solution implementation
template <unsigned prob_num, class problem_t> class Problem_ {
public:
  void solution(unsigned long n) {
    std::cout << "Problem " << prob_num << ": ";

    problem_t *problem = static_cast<problem_t *>(this);
    std::string time_str;
    {
      Timer timer(time_str);
      problem->solution_impl(n);
    }

    std::cout << " (" << time_str << ")" << std::endl;
  }
};