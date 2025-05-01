#include "problem.hpp"

#include <cmath>
#include <iostream>
#include <set>

class Problem : public Problem_<23, Problem> {
  friend class Problem_<23, Problem>;

  std::set<int> abundants_;

public:
  Problem() {
    // Precompute abundants
    for (int n = 12; n <= 28123; n++)
      if (is_abundant(n))
        abundants_.insert(n);
  }

private:
  void solution_impl(unsigned long) {
    // 1-11 given
    int sum{};
    for (int i = 1; i < 12; i++)
      sum += i;

    // Check lower limit thru upper limit
    for (int i = 12; i <= 28123; i++)
      if (!abundant_summable(i))
        sum += i;

    std::cout << sum;
  }

  bool is_abundant(int n) {
    int sumDiv{};
    for (int i = 1; i <= n / 2; i++)
      if (n % i == 0)
        sumDiv += i;

    return sumDiv > n;
  }

  bool abundant_summable(int n) {
    for (int a : abundants_) {
      if (a >= n)
        break;

      if (abundants_.find(n - a) != abundants_.end())
        return true;
    }

    return false;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
