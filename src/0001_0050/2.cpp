#include "problem.hpp"
#include <cassert>

class Problem : public Problem_<2, Problem> {
  friend class Problem_<2, Problem>;

  void solution_impl(unsigned long n) {
    unsigned long a{1}, b{1}, tmp{}, sum{};
    while (tmp < n) {
      tmp = a + b;
      if (tmp % 2 == 0)
        sum += tmp;

      a = b;
      b = tmp;
    }

    assert(sum == 4613732);
    std::cout << sum;
  }
};

int main() {
  Problem prob;
  prob.solution(4'000'000);
}