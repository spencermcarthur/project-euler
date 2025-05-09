#include "problem.hpp"
#include <cassert>
#include <iostream>
#include <string>

class Problem : public Problem_<40, Problem> {
  friend class Problem_<40, Problem>;

  void solution_impl(unsigned long) {
    unsigned n{1};
    std::string s;
    while (s.size() < 1'000'000)
      s += std::to_string(n++);

    unsigned prod{1};
    for (size_t i = 1; i <= 1'000'000; i *= 10)
      prod *= (s[i - 1] - '0');

    assert(prod == 210);
    std::cout << prod;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
