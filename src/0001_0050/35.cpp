#include "prime.hpp"
#include "problem.hpp"

#include <cassert>
#include <cmath>
#include <iostream>
#include <unordered_set>

class Problem : public Problem_<35, Problem> {
  friend class Problem_<35, Problem>;

  const std::unordered_set<unsigned long> primes;
  // There are 78,498 primes below 1 million
  static constexpr unsigned np = 78'498;

public:
  Problem() : primes(get_n_primes_uset(np)) {}

private:
  void solution_impl(unsigned long) {
    unsigned count{};
    for (unsigned n : primes)
      if (is_circular(n))
        count++;

    assert(count == 55);
    std::cout << count;
  }

  bool is_circular(unsigned n) {
    if (n < 10)
      return true;

    const unsigned x = std::pow(10, std::floor(std::log10(n)));
    unsigned tmp = n;
    do {
      tmp = rotate(tmp, x);
      if (primes.find(tmp) == primes.end())
        return false;
    } while (tmp != n);

    return true;
  }

  unsigned rotate(unsigned n, const unsigned x) {
    return (n % 10) * x + n / 10;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
