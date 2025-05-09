#include "problem.hpp"

#include <cassert>
#include <cmath>
#include <set>
#include <unordered_map>
#include <utility>

class Problem : public Problem_<21, Problem> {
  friend class Problem_<21, Problem>;

  void solution_impl(unsigned long n) {
    std::set<std::pair<unsigned long, unsigned long>> amicable_pairs;
    for (unsigned long a = 2; a < n; a++) {
      unsigned long b = d(a);
      if (a == d(b) && a != b) {
        // Order pairs to ensure they dont get duplicated
        if (a < b)
          amicable_pairs.insert({a, b});
        else
          amicable_pairs.insert({b, a});
      }
    }

    unsigned long sum{};
    for (auto [a, b] : amicable_pairs)
      sum += a + b;

    assert(sum == 31626);
    std::cout << sum;
  }

  std::unordered_map<unsigned long, unsigned long> cache_;
  unsigned long d(unsigned long n) {
    if (cache_.find(n) != cache_.end())
      return cache_[n];

    unsigned long sum{1};
    for (unsigned long i = 2; i <= std::sqrt(n); i++) {
      if (n % i == 0) {
        if (i * i == n)
          sum += i;
        else
          sum += i + n / i;
      }
    }

    return cache_[n] = sum;
  }
};

int main() {
  Problem prob;
  prob.solution(10'000);
}
