#pragma once

#include <iostream>

#include "timer.hpp"

template <unsigned SolnNum, class ProblemT> class Problem_ {
public:
  void solution(unsigned long n) {
    std::cout << "Problem " << SolnNum << ": ";

    ProblemT *prob = static_cast<ProblemT *>(this);
    std::string s;
    {
      Timer t(s);
      prob->solution_impl(n);
    }

    std::cout << " (" << s << ")" << std::endl;
  }
};