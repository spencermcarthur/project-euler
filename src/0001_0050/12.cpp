#include "problem.hpp"
#include "util.hpp"

#include <cassert>
#include <cmath>

class Problem : public Problem_<12, Problem> {
  friend class Problem_<12, Problem>;

public:
  Problem() {}

private:
  void solution_impl(unsigned long n) {
    unsigned long i{}, div{}, tri;
    while (div <= n) {
      tri = nth_triangular(++i);
      div = count_divisors(tri);
    }

    assert(tri == 76576500);
    std::cout << tri;
  }

  unsigned long nth_triangular(unsigned long n) {
    if (n % 2 == 0)
      return n / 2 * (n + 1);
    else
      return (n + 1) / 2 * n;
  }
};

int main() {
  Problem prob;
  //   prob.solution(5);
  prob.solution(500);
}