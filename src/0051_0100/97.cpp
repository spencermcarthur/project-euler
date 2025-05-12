#include "problem.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

class Problem : public Problem_<97, Problem> {
  friend class Problem_<97, Problem>;

  void solution_impl(unsigned long) {
    unsigned long x = std::pow(10, 10);

    unsigned long p = 28433;
    for (int i = 0; i < 7830457; i++)
      p = (p * 2) % x;

    p++;

    assert(p == 8739992577);
    std::cout << p;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
