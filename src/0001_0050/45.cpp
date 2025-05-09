#include "problem.hpp"
#include "util.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

class Problem : public Problem_<45, Problem> {
  friend class Problem_<45, Problem>;

  void solution_impl(unsigned long) {
    unsigned long tri;
    for (unsigned long n = 286;; n++) {
      tri = (n % 2 == 0) ? n / 2 * (n + 1) : (n + 1) / 2 * n;
      if (is_pent(tri) && is_hex(tri))
        break;
    }

    assert(tri == 1533776805);
    std::cout << tri;
  }

  bool is_pent(unsigned long p) {
    // From quadratic formula
    return is_integral((1.0 + std::sqrt(1 + 24 * p)) / 6.0);
  }

  bool is_hex(unsigned long h) {
    // From quadratic formula
    return is_integral((1.0 + std::sqrt(1 + 8 * h)) / 4.0);
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
