#include "prime.hpp"
#include "problem.hpp"
#include <cassert>

class Problem : public Problem_<10, Problem> {
  friend class Problem_<10, Problem>;

  void solution_impl(unsigned long n) {
    std::vector<bool> prime = sieve(n);
    unsigned long sum{0};
    for (unsigned long i = 0; i < n; i++)
      if (prime[i])
        sum += i;

    assert(sum == 142913828922);
    std::cout << sum;
  }
};

int main() {
  Problem prob;
  // prob.solution(10);
  prob.solution(2'000'000);
}