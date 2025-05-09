#include "prime.hpp"
#include "problem.hpp"
#include "util.hpp"

#include <cassert>
#include <cmath>
#include <iostream>
#include <set>

class Problem : public Problem_<46, Problem> {
  friend class Problem_<46, Problem>;

  std::set<unsigned long> primes;

public:
  Problem() { primes = get_n_primes_set(1'000); }

private:
  void solution_impl(unsigned long) {
    unsigned long res;
    for (unsigned long n = 4;; n++) {
      // Must be composite
      if (primes.find(n) != primes.end())
        continue;

      if (n % 2 == 1 && !check(n)) {
        res = n;
        break;
      }
    }

    assert(res == 5777);
    std::cout << res;
  }

  bool check(unsigned long n) {
    double rem;
    for (auto p : primes) {
      if (p > n)
        break;

      // Check if remainder is twice a square
      rem = n - p;
      rem = std::sqrt(rem / 2.0);
      if (is_integral(rem))
        return true;
    }
    return false;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
