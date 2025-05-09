#include "prime.hpp"
#include "problem.hpp"
#include <cassert>

class Problem : public Problem_<7, Problem> {
  friend class Problem_<7, Problem>;

  void solution_impl(unsigned long k) {
    unsigned long i{0}, n{0};
    while (i < k) {
      if (is_prime(++n))
        i++;
    }

    assert(n == 104743);
    std::cout << n;
  }
};

int main() {
  Problem prob;
  // prob.solution(6);
  prob.solution(10001);
}