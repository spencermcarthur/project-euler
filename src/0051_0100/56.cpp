#include "problem.hpp"

#include <boost/multiprecision/cpp_int.hpp>
#include <cassert>
#include <iostream>

namespace boost {
namespace multiprecision {
using big_uint =
    number<cpp_int_backend<2048, 2048, unsigned_magnitude, unchecked, void>>;
}
} // namespace boost

using boost::multiprecision::big_uint;

class Problem : public Problem_<56, Problem> {
  friend class Problem_<56, Problem>;

  void solution_impl(unsigned long) {
    unsigned max{}, res{};
    for (unsigned a = 2; a < 100; a++) {
      for (unsigned b = 2; b < 100; b++) {
        res = sum_digits(pow(a, b));
        if (res > max)
          max = res;
      }
    }

    assert(max == 972);
    std::cout << max;
  }

  big_uint pow(unsigned a, unsigned b) {
    big_uint res{1};
    for (unsigned i = 0; i < b; i++)
      res *= a;
    return res;
  }

  unsigned sum_digits(big_uint n) {
    unsigned sum{};
    while (n > 0) {
      sum += (unsigned)(n % 10);
      n /= 10;
    }
    return sum;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
