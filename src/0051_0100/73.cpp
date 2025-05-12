#include "problem.hpp"
#include <cassert>
#include <iostream>
#include <numeric>

struct Fraction {
  Fraction(int num, int denom)
      : num(num), denom(denom), val((double)num / (double)denom) {}

  int num;
  int denom;
  double val;

  friend bool operator<(const Fraction &l, const Fraction &r) {
    return l.val < r.val;
  }
};

class Problem : public Problem_<73, Problem> {
  friend class Problem_<73, Problem>;

  void solution_impl(unsigned long) {
    unsigned count{};
    const Fraction one_third(1, 3);
    const Fraction one_half(1, 2);
    for (int d = 2; d <= 12'000; d++) {
      for (int n = 1; n < d; n++) {
        if (std::gcd(n, d) != 1)
          continue;

        Fraction f(n, d);
        if (one_third < f && f < one_half)
          count++;
      }
    }

    assert(count == 7295372);
    std::cout << count;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
