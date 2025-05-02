#include "problem.hpp"
#include <cassert>

class Problem : public Problem_<28, Problem> {
  friend class Problem_<28, Problem>;

  void solution_impl(unsigned long n) {
    unsigned long sum{1};
    unsigned diff{2}, jump{4}, x{1};

    for (unsigned i = 0; i < n / 2; i++) {
      for (unsigned j = 0; j < 4; j++) {
        x += diff;
        sum += x;
      }

      x += (jump - diff - 2);

      diff += 2;
      jump += 2;
    }

    assert(sum == 669171001);
    std::cout << sum;
  }
};

int main() {
  Problem prob;
  //   prob.solution(5);
  prob.solution(1001);
}
