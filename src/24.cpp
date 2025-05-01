#include "problem.hpp"

#include <algorithm>
#include <iostream>
#include <string>

class Problem : public Problem_<24, Problem> {
  friend class Problem_<24, Problem>;

  void solution_impl(unsigned long) {
    std::string s{"0123456789"};

    unsigned count{};
    for (int i = 0; i < 999'999; i++)
      std::next_permutation(s.begin(), s.end());

    std::cout << s;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
