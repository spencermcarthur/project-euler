#include "problem.hpp"

#include <cassert>
#include <iostream>

class Problem : public Problem_<53, Problem> {
  friend class Problem_<53, Problem>;

  void solution_impl(unsigned long) {
    unsigned count{};
    for (unsigned n = 23; n <= 100; n++) {
      for (unsigned r = 1; r < n; r++) {
        if (choose(n, r) > 1'000'000)
          count++;
      }
    }

    assert(count == 4075);
    std::cout << count;
  }

  double choose(unsigned n_, unsigned r_) {
    if (r_ == 1 || r_ == n_ - 1)
      return n_;
    else if (r_ == n_)
      return 1;

    double res{1};
    unsigned n{n_}, r{r_}, nmr{n_ - r_};
    while (n > 1 || r > 1 || nmr > 1) {
      if (n > 1)
        res *= n--;
      if (r > 1)
        res /= r--;
      if (nmr > 1)
        res /= nmr--;
    }

    return res;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
