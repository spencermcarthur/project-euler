#include "problem.hpp"
#include <unordered_map>

class Problem : public Problem_<15, Problem> {
  friend class Problem_<15, Problem>;

  void solution_impl(unsigned long n) { std::cout << recursion(n, n); }

  std::unordered_map<unsigned long, unsigned long> memo;

  unsigned long recursion(unsigned long m, unsigned long n) {
    // Base case
    if (m == 0 || n == 0)
      return 1;

    // Compute pair value, choosing the larger value first, since ordering is
    // arbitrary
    unsigned long pair = m > n ? cantor(m, n) : cantor(n, m);

    // Check memo
    if (memo.find(pair) != memo.end())
      return memo[pair];

    // Else, compute and store
    memo[pair] = recursion(m - 1, n) + recursion(m, n - 1);
    return memo[pair];
  }

  // Uniquely pair two numbers for hashing
  unsigned long cantor(unsigned long m, unsigned long n) {
    return (m + n) * (m + n + 1) / 2 + n;
  }
};

int main() {
  Problem prob;
  //   prob.solution(2);
  prob.solution(20);
}
