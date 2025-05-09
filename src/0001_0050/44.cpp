#include "problem.hpp"

#include <cassert>
#include <iostream>
#include <limits>
#include <unordered_set>

class Problem : public Problem_<44, Problem> {
  friend class Problem_<44, Problem>;

  static constexpr unsigned num_pent{3'000};
  std::unordered_set<unsigned> pent;

public:
  Problem() {
    pent.reserve(num_pent);
    for (unsigned n = 1; n <= num_pent; n++)
      pent.insert(n * (3 * n - 1) / 2);
  }

private:
  void solution_impl(unsigned long) {
    unsigned min_diff{std::numeric_limits<unsigned>::max()};
    for (unsigned p1 : pent) {
      for (unsigned p2 : pent) {
        if (p1 == p2)
          continue;

        unsigned D = (p1 < p2) ? p2 - p1 : p1 - p2;
        if (is_pent(p1 + p2) && is_pent(D)) {
          if (D < min_diff)
            min_diff = D;
        }
      }
    }

    assert(min_diff == 5482660);
    std::cout << min_diff;
  }

  bool is_pent(unsigned n) { return pent.find(n) != pent.end(); }
};

int main() {
  Problem prob;
  prob.solution(0);
}
