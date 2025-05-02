#include "problem.hpp"

#include <cassert>
#include <cmath>

class Problem : public Problem_<30, Problem> {
  friend class Problem_<30, Problem>;

  void solution_impl(unsigned long p) {
    unsigned long sum{};
    for (unsigned i = 1; i < 1000000; i++)
      if (possible(i, p))
        sum += i;

    assert(sum == 443839);
    std::cout << sum;
  }

  bool possible(unsigned n, unsigned p) {
    if (n == 1)
      return false;

    unsigned sum{}, pow{}, n_{n};
    while (n_ != 0) {
      pow = my_pow(n_ % 10, p);
      sum += pow;
      n_ /= 10;
    }
    return sum == n;
  }

  unsigned my_pow(unsigned n, unsigned p) {
    if (n == 1)
      return 1;
    if (p == 1)
      return n;

    unsigned prod{1};
    for (unsigned i = 0; i < p; i++)
      prod *= n;
    return prod;
  }
};

int main() {
  Problem prob;
  //   prob.solution(4);
  prob.solution(5);
}
