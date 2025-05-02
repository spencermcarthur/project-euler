#include "problem.hpp"
#include <cassert>

class Problem : public Problem_<9, Problem> {
  friend class Problem_<9, Problem>;

  void solution_impl(unsigned long n) {
    unsigned long prod{0}, c;
    bool done{false};
    for (unsigned long a = 1; a <= 332; a++) {
      for (unsigned long b = a + 1; b < (n - a - 1) / 2; b++) {
        c = n - a - b;
        if (a * a + b * b == c * c) {
          done = true;
          prod = a * b * c;
          break;
        }
      }
      if (done)
        break;
    }

    assert(prod == 31875000);
    std::cout << prod;
  }
};

int main() {
  Problem prob;
  prob.solution(1000);
}