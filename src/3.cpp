#include "prime.hpp"
#include "problem.hpp"

class Problem : public Problem_<3, Problem> {
  friend class Problem_<3, Problem>;

  void solution_impl(unsigned long n) {
    const unsigned long ul = std::ceil(std::sqrt(n));
    const std::vector<bool> prime = sieve(ul);
    unsigned long lpf{0};
    for (unsigned long i = 3; i <= ul; i += 2)
      if (prime[i] && n % i == 0)
        lpf = i;
    std::cout << lpf;
  }
};

int main() {
  Problem prob;
  // prob.solution(13195);
  prob.solution(600851475143);
}