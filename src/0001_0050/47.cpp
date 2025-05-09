#include "prime.hpp"
#include "problem.hpp"

#include <cassert>
#include <iostream>
#include <set>

class Problem : public Problem_<47, Problem> {
  friend class Problem_<47, Problem>;

  std::set<unsigned long> primes;

public:
  Problem() : primes(get_n_primes_set(15'000)) {}

private:
  void solution_impl(unsigned long n_consecutive) {
    unsigned consecutive_count{}, first{};
    for (unsigned n = 647; consecutive_count < n_consecutive; n++) {
      // Skip primes
      if (primes.find(n) != primes.end()) {
        consecutive_count = 0;
        continue;
      }

      if (count_distinct_prime_factors(n) == n_consecutive) {
        if (++consecutive_count == 1)
          first = n;
      } else {
        consecutive_count = 0;
      }
    }

    assert(first == 134043);
    std::cout << first;
  }

  unsigned count_distinct_prime_factors(unsigned n) {
    std::set<unsigned> pf;
    while (n > 1) {
      if (primes.find(n) != primes.end()) {
        pf.insert(n);
        break;
      }

      for (unsigned p : primes) {
        if (n % p == 0) {
          n /= p;
          pf.insert(p);
          break;
        }
      }
    }
    return pf.size();
  }
};

int main() {
  Problem prob;
  //   prob.solution(2);
  //   prob.solution(3);
  prob.solution(4);
}
