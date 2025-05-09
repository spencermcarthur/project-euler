#include "problem.hpp"

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/number.hpp>
#include <cassert>

namespace mp = boost::multiprecision;

class Problem : public Problem_<20, Problem> {
  friend class Problem_<20, Problem>;

  void solution_impl(unsigned long) {
    mp::uint1024_t f{1};
    for (unsigned n = 2; n <= 100; n++)
      f *= n;

    unsigned sum{};
    for (char c : mp::to_string(f))
      sum += (c - '0');

    assert(sum == 648);
    std::cout << sum;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
