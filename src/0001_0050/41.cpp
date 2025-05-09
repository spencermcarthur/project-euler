#include "prime.hpp"
#include "problem.hpp"

#include <cassert>
#include <iostream>
#include <unordered_map>

class Problem : public Problem_<41, Problem> {
  friend class Problem_<41, Problem>;

  void solution_impl(unsigned long) {
    unsigned max{};
    for (unsigned p : get_n_primes(600'000)) {
      if (is_pandigital(p))
        max = p;
    }

    assert(max == 7652413);
    std::cout << max;
  }

  bool is_pandigital(unsigned n) {
    // Check frequencies
    std::unordered_map<unsigned, unsigned> freq(9);
    while (n > 0) {
      if (++freq[n % 10] > 1)
        return false;
      n /= 10;
    }

    // Check consecutive
    for (unsigned n = 1; n <= freq.size(); n++)
      if (freq.find(n) == freq.end())
        return false;

    return true;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
