#include "problem.hpp"

#include <cassert>
#include <cmath>
#include <iostream>
#include <unordered_map>

class Problem : public Problem_<39, Problem> {
  friend class Problem_<39, Problem>;

  void solution_impl(unsigned long) {
    unsigned max{}, argmax{};
    std::unordered_map<unsigned, unsigned> counts;

    // Lower bound: 3-4-5
    for (int a = 3; a <= 998; a++) {
      for (int b = 4; b <= 999; b++) {
        int c = std::sqrt(a * a + b * b);
        if (c * c != a * a + b * b)
          continue;

        unsigned p = a + b + c;
        if (p > 1000)
          continue;

        if (++counts[p] > max) {
          max = counts[p];
          argmax = p;
        }
      }
    }

    assert(argmax == 840);
    std::cout << argmax;
  }

  bool check(int a, int b, int c) { return a * a + b * b - c * c == 0; }
};

int main() {
  Problem prob;
  prob.solution(0);
}
