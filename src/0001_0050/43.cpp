#include "problem.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Problem : public Problem_<43, Problem> {
  friend class Problem_<43, Problem>;

  void solution_impl(unsigned long) {
    unsigned long sum{};
    std::string s{"0123456789"};
    do {
      if (check(s))
        sum += std::stoul(s);
    } while (std::next_permutation(s.begin(), s.end()));

    assert(sum == 16695334890);
    std::cout << sum;
  }

  const std::vector<unsigned> primes{2, 3, 5, 7, 11, 13, 17};
  bool check(const std::string &s) {
    for (unsigned i = 0; i < primes.size(); i++)
      if (std::stoul(s.substr(i + 1, 3)) % primes[i] != 0)
        return false;

    return true;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
