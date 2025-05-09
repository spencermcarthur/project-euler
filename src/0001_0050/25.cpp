#include "problem.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

class Problem : public Problem_<25, Problem> {
  friend class Problem_<25, Problem>;

  void solution_impl(unsigned long) {
    // n(F) = round( log10(sqrt(5) * F) / log10(phi) )
    // Where phi = golden ratio = (1 + sqrt(5)) / 2
    // Since we want the first F with 1000 digits, we use ceil instead of round
    // Expand the log of product:
    // n(F) = ceil( (log10(sqrt(5)) + log10(F)) / log10(phi) )
    // If F has 1000 digits, 999 <= log10(F) < 1000
    // So n(F) = ceil( (log10(sqrt(5)) + 999) / log10(phi) )

    const double phi = (1 + std::sqrt(5)) / 2;
    unsigned n = std::ceil((std::log10(std::sqrt(5)) + 999) / std::log10(phi));

    assert(n == 4782);
    std::cout << n;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
