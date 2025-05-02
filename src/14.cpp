#include "problem.hpp"

#include <cassert>
#include <unordered_map>

class Problem : public Problem_<14, Problem> {
  friend class Problem_<14, Problem>;

  void solution_impl(unsigned long n) {
    unsigned long argMax{}, maxSeqLen{}, seqLen;
    for (unsigned long i = 1; i < n; i++) {
      seqLen = collatz(i);
      if (seqLen > maxSeqLen) {
        argMax = i;
        maxSeqLen = seqLen;
      }
    }

    assert(argMax == 837799);
    std::cout << argMax;
  }

  std::unordered_map<unsigned long, unsigned long> memo;

  unsigned long collatz(unsigned long n) {
    // Base case
    if (n == 1)
      return 0;

    // Look in memo
    if (memo.find(n) != memo.end())
      return memo[n];

    // Else compute and store
    if (n % 2 == 0)
      memo[n] = 1 + collatz(n / 2);
    else
      memo[n] = 1 + collatz(3 * n + 1);

    return memo[n];
  }
};

int main() {
  Problem prob;
  // prob.solution(10);
  prob.solution(1'000'000);
}
