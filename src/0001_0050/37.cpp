#include "prime.hpp"
#include "problem.hpp"

#include <cassert>
#include <cmath>
#include <iostream>
#include <set>

class Problem : public Problem_<37, Problem> {
  friend class Problem_<37, Problem>;

  std::set<unsigned long> primes;

public:
  //   Problem() : primes{7, 97, 797, 3797, 3, 37, 379} {}
  Problem() : primes(get_n_primes_set(100'000)) {}

private:
  void solution_impl(unsigned long) {
    unsigned count{}, sum{};

    for (auto p : primes) {
      if (p < 10)
        continue;

      if (left_right(p) && right_left(p)) {
        sum += p;
        count++;
      }

      if (count == 11)
        break;
    }

    assert(sum == 748317);
    std::cout << sum;
  }

  bool left_right(unsigned long n) {
    unsigned x = std::pow(10, (unsigned)std::log10(n));

    unsigned long tmp{n};
    while (tmp > 10) {
      n = n % x;
      x /= 10;
      tmp /= 10;

      if (primes.find(n) == primes.end())
        return false;
    }
    return true;
  }

  bool right_left(unsigned long n) {
    do {
      n /= 10;
      if (primes.find(n) == primes.end())
        return false;
    } while (n > 10);
    return true;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
