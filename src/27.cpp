#include "prime.hpp"
#include "problem.hpp"

#include <cassert>
#include <utility>

class Problem : public Problem_<27, Problem> {
  friend class Problem_<27, Problem>;

  void solution_impl(unsigned long) {
    long maxCount{};
    std::pair<long, long> maxCoeff{};

    long a, b;
    for (a = -999; a < 1000; a++) {
      for (b = -1000; b <= 1000; b++) {
        long count = count_primes(a, b);
        if (count > maxCount) {
          maxCount = count;
          maxCoeff = {a, b};
        }
      }
    }

    long prod = maxCoeff.first * maxCoeff.second;

    assert(prod == -59231);
    std::cout << prod;
  }

  long count_primes(long a, long b) {
    long n, res;
    for (n = 0;; n++) {
      res = n * n + a * n + b;
      if (res < 2 || !is_prime_memoized(res))
        break;
    }

    return n + 1;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
