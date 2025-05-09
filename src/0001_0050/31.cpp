#include "problem.hpp"
#include "util.hpp"

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

class Problem : public Problem_<31, Problem> {
  friend class Problem_<31, Problem>;

  const std::vector<unsigned> coins{1, 2, 5, 10, 20, 50, 100, 200};

  void solution_impl(unsigned long n) {
    unsigned res = recurse(0, n);

    assert(res == 73682);
    std::cout << res;
  }

  std::unordered_map<unsigned long, unsigned> memo;
  unsigned recurse(unsigned i, unsigned sum) {
    // Base cases
    if (sum == 0)
      return 1;
    else if (i == coins.size())
      return 0;

    // Check memo
    unsigned long p = pair(i, sum);
    if (memo.find(p) != memo.end())
      return memo[p];

    // Count ways if we include the current coin
    unsigned take{};
    if (coins[i] <= sum)
      take = recurse(i, sum - coins[i]);

    // Count ways if we exclude the current coin
    unsigned skip = recurse(i + 1, sum);

    return memo[p] = take + skip;
  }
};

int main() {
  Problem prob;
  // prob.solution(5);
  prob.solution(200);
}
