#include "problem.hpp"

class Problem : public Problem_<6, Problem> {
  friend class Problem_<6, Problem>;

  void solution_impl(unsigned long n) {
    const unsigned long sum = n * (n + 1) / 2;
    unsigned long sumSq{};
    for (unsigned long i = 1; i <= n; i++)
      sumSq += i * i;

    std::cout << sum * sum - sumSq;
  }
};

int main() {
  Problem prob;
  // prob.solution(10);
  prob.solution(100);
}