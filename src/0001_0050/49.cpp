#include "prime.hpp"
#include "problem.hpp"

#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

class Problem : public Problem_<49, Problem> {
  friend class Problem_<49, Problem>;

  std::set<unsigned> primes_vec;

public:
  Problem() {
    for (unsigned p = 1'000; p < 10'000; p++) {
      if (is_prime(p))
        primes_vec.insert(p);
    }
  }

private:
  void solution_impl(unsigned long) {
    std::set<std::set<unsigned>> sequences;
    for (unsigned n : primes_vec) {
      std::set<unsigned> seq = check_and_get_sequence(n);
      if (!seq.empty())
        sequences.insert(seq);
    }

    std::string res;
    for (const auto &seq : sequences) {
      if (*seq.begin() == 1487)
        continue;

      for (unsigned n : seq)
        res += std::to_string(n);
    }

    assert(res == "296962999629");
    std::cout << res;
  }

  std::set<unsigned> check_and_get_sequence(unsigned n) {
    std::set<unsigned> res;
    for (unsigned d = 2; n + 2 * d < 10'000; d++) {
      if (is_prime_memoized(n + d) && is_prime_memoized(n + 2 * d)) {
        if (is_perm(n, n + d) && is_perm(n, n + 2 * d)) {
          res.insert(n);
          res.insert(n + d);
          res.insert(n + 2 * d);
        }
      }
    }
    return res;
  }

  bool is_perm(unsigned x, unsigned y) {
    std::unordered_map<unsigned, unsigned> xcount, ycount;
    while (x > 0) {
      xcount[x % 10]++;
      x /= 10;
    }

    while (y > 0) {
      ycount[y % 10]++;
      y /= 10;
    }

    for (auto [n, c] : xcount)
      if (c != ycount[n])
        return false;

    return true;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
