#include "problem.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

class Problem : public Problem_<24, Problem> {
  friend class Problem_<24, Problem>;

  void solution_impl(unsigned long) {
    std::string s{"0123456789"};

    for (int i = 0; i < 999'999; i++)
      std::next_permutation(s.begin(), s.end());

    unsigned long perm = std::stoull(s);

    assert(perm == 2783915460);
    std::cout << perm;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
