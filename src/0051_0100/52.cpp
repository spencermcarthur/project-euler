#include "problem.hpp"

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

class Problem : public Problem_<52, Problem> {
  friend class Problem_<52, Problem>;

  void solution_impl(unsigned long) {
    bool done{false};
    unsigned long res{};
    for (unsigned long n = 1; !done; n++) {
      for (unsigned long x = 2; x <= 6; x++) {
        if (!compare_digits(n, x * n))
          break;
        if (x == 6) {
          done = true;
          res = n;
        }
      }
    }

    assert(res == 142857);
    std::cout << res;
  }

  bool compare_digits(unsigned long a, unsigned long b) {
    std::string sa(std::to_string(a)), sb(std::to_string(b));
    std::unordered_map<char, unsigned> afreq, bfreq;

    for (char c : sa)
      afreq[c]++;
    for (char c : sb)
      bfreq[c]++;

    for (auto [c, n] : afreq)
      if (n != bfreq[c])
        return false;

    return true;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
