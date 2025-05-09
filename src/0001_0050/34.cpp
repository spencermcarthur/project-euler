#include "problem.hpp"
#include <cassert>
#include <iostream>

class Problem : public Problem_<34, Problem> {
  friend class Problem_<34, Problem>;

  void solution_impl(unsigned long) {
    unsigned long sum{};
    // Analytic upper bound = 9,999,999: 7*9! < 9,999,999
    // Empirical upper bound: 40,585
    for (unsigned n = 3; n <= 40'585; n++)
      if (check(n))
        sum += n;

    assert(sum == 40730);
    std::cout << sum;
  }

  bool check(unsigned n) {
    unsigned sum{}, tmp{n};
    while (tmp != 0) {
      unsigned dig = tmp % 10;
      sum += factorial(dig);
      tmp /= 10;
    }
    return sum == n;
  }

  unsigned factorial(unsigned n) {
    unsigned prod{1};
    for (unsigned i = n; i > 1; i--)
      prod *= i;
    return prod;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
