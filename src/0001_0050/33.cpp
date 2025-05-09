#include "problem.hpp"
#include "util.hpp"

#include <cassert>
#include <numeric>

class Problem : public Problem_<33, Problem> {
  friend class Problem_<33, Problem>;

  void solution_impl(unsigned long) {
    unsigned pn{1}, pd{1};
    for (unsigned n = 10; n < 99; n++) {
      for (unsigned d = n + 1; d < 100; d++) {
        if (n % 10 == 0 && d % 10 == 0)
          continue;

        unsigned num[2] = {n / 10, n % 10};
        unsigned denom[2] = {d / 10, d % 10};
        double frac = (double)n / (double)d;

        if (num[0] == denom[0]) {
          if (check(num[1], denom[1], frac)) {
            pn *= num[1];
            pd *= denom[1];
          }
        } else if (num[0] == denom[1]) {
          if (check(num[1], denom[0], frac)) {
            pn *= num[1];
            pd *= denom[0];
          }
        } else if (num[1] == denom[0]) {
          if (check(num[0], denom[1], frac)) {
            pn *= num[0];
            pd *= denom[1];
          }
        } else if (num[1] == denom[1]) {
          if (check(num[0], denom[0], frac)) {
            pn *= num[0];
            pd *= denom[0];
          }
        }
      }
    }

    unsigned res = pd / std::gcd(pn, pd);

    assert(res == 100);
    std::cout << res;
  }

  bool check(unsigned a, unsigned d, double f) {
    return dbl_equal((double)a / (double)d, f);
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
