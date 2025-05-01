#include "problem.hpp"

#include <numeric>

// https://en.wikipedia.org/wiki/Least_common_multiple#Other

class Problem : public Problem_<5, Problem> {
  friend class Problem_<5, Problem>;

  void solution_impl(unsigned long n) {
    unsigned long res{1};
    for (unsigned long i = 2; i <= n; i++)
      res = lcm(res, i);

    std::cout << res;
  }

  unsigned long lcm(unsigned long a, unsigned long b) {
    return a / std::gcd(a, b) * b;
  }
};

int main() {
  Problem prob;
  // prob.solution(10);
  prob.solution(20);
}