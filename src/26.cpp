#include "prime.hpp"
#include "problem.hpp"
#include "util.hpp"

#include <cassert>
#include <string>
#include <vector>

class Problem : public Problem_<26, Problem> {
  friend class Problem_<26, Problem>;

  void solution_impl(unsigned long n) {
    // Only considering prime divisors
    // Need ~200 to reach 1000
    const std::vector<unsigned long> primes = get_n_primes(200);

    unsigned max{}, argMax{};
    for (unsigned d : primes) {
      // Skip some
      if (d < 7)
        continue;
      else if (d > n)
        break;

      // Long division up to 10,000 places
      std::string s = long_divide(d);

      // Trim trailing zeros
      trim_trailing(s, '0');

      // Find first non-zero digit as start of sequence
      size_t i = s.find_first_not_of('0'), repSeqLen{1};

      // Loop until sequence starting at `i` of length `repSeqLen` is the same
      // as the sequence starting at `i+repSeqLen` of length `repSeqLen`
      while (s.substr(i, repSeqLen) != s.substr(i + repSeqLen, repSeqLen))
        repSeqLen++;

      // Record new maximum
      if (repSeqLen > max) {
        max = repSeqLen;
        argMax = d;
      }
    }

    assert(argMax == 983);
    std::cout << argMax;
  }

  std::string long_divide(unsigned denom, unsigned num = 1) {
    constexpr unsigned size = 2000;

    std::string s;
    s.reserve(size);

    unsigned dig, rem;
    while (s.size() < size) {
      num *= 10;
      dig = num / denom;
      rem = num % denom;

      s += '0' + dig;

      num = rem;
    }

    return s;
  }
};

int main() {
  Problem prob;
  prob.solution(1000);
}
