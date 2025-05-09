#include "problem.hpp"
#include "util.hpp"
#include <bitset>
#include <cassert>
#include <iostream>
#include <string>

class Problem : public Problem_<36, Problem> {
  friend class Problem_<36, Problem>;

  void solution_impl(unsigned long) {
    unsigned sum{};
    std::string dec, bin;
    for (unsigned n = 1; n < 1'000'000; n++) {
      dec = std::to_string(n);
      if (!is_palindrome(dec))
        continue;

      bin = std::bitset<sizeof(n) * 8>(n).to_string();
      trim_leading(bin, '0');
      if (is_palindrome(bin))
        sum += n;
    }

    assert(sum == 872187);
    std::cout << sum;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
