#include "problem.hpp"

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/fwd.hpp>
#include <cassert>
#include <cmath>
#include <iostream>
#include <unordered_map>

using big_num = boost::multiprecision::uint1024_t;

class Problem : public Problem_<78, Problem> {
  friend class Problem_<78, Problem>;

  void solution_impl(unsigned long) {
    unsigned long n;
    big_num part;
    for (n = 0;; n++) {
      part = p(n);
      if (part % 1'000'000 == 0)
        break;
    }

    assert(n == 55374);
    std::cout << n;
  }

  std::unordered_map<long, big_num> memo;

  // Implmentation of recurrence relation for integer partition function:
  // https://en.wikipedia.org/wiki/Partition_function_(number_theory)#Recurrence_relations
  big_num p(long n) {
    if (n < 0)
      return 0;
    else if (n <= 1)
      return 1;

    // Memoization is necessary for runtime
    if (memo.find(n) != memo.end())
      return memo[n];

    const long x = 24 * n + 1;
    const long k_lower_limit = std::ceil(-(std::sqrt(x) - 1) / 6);
    const long k_upper_limit = std::floor((std::sqrt(x) + 1) / 6);

    big_num sum{};

    // Handle additions first to avoid underflow. Using int1024_t would work as
    // well, but for some reason this is faster.
    for (long k = k_lower_limit; k <= k_upper_limit; k++) {
      if (k == 0)
        continue;

      if ((k + 1) % 2 == 0)
        sum += p(n - k * (3 * k - 1) / 2);
    }

    for (long k = k_lower_limit; k <= k_upper_limit; k++) {
      if (k == 0)
        continue;

      if ((k + 1) % 2 != 0)
        sum -= p(n - k * (3 * k - 1) / 2);
    }

    return memo[n] = sum;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
