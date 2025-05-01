#include "problem.hpp"

class Problem : public Problem_<1, Problem> {
  friend class Problem_<1, Problem>;

  void solution_impl(unsigned long n) {
    unsigned long sum{};
    for (unsigned long i = 0; i < n; i++)
      if (i % 3 == 0 || i % 5 == 0)
        sum += i;
    std::cout << sum;
  }
};

int main() {
  Problem prob;
  // prob.solution(10);
  prob.solution(1000);
}
