#include "problem.hpp"

#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

class Problem : public Problem_<16, Problem> {
  friend class Problem_<16, Problem>;

  void solution_impl(unsigned long n) {
    mp::uint1024_t res = 1;
    for (int i = 0; i < n; i++)
      res *= 2;

    std::string s = mp::to_string(res);
    unsigned sum{};
    for (char c : s)
      sum += (c - '0');

    std::cout << sum;
  }
};

int main() {
  Problem prob;
  //   prob.solution(15);
  prob.solution(1000);
}
