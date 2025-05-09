#include "problem.hpp"

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/number.hpp>
#include <cassert>
#include <iostream>
#include <string>

namespace boost::multiprecision {
using huge_uint =
    // Dominant term: 1000^1000 = 1e3000
    // log2(1e3000) is less than 10,000, but only by a little
    number<cpp_int_backend<10000, 10000, unsigned_magnitude, unchecked, void>>;
}
using boost::multiprecision::huge_uint;
using boost::multiprecision::to_string;

class Problem : public Problem_<48, Problem> {
  friend class Problem_<48, Problem>;

  void solution_impl(unsigned long n) {
    huge_uint sum{};
    for (unsigned x = 1; x <= n; x++)
      sum += pow(x, x);

    std::string s = to_string(sum);
    s = s.substr(s.size() - 10);

    // assert(s == "0405071317");
    assert(s == "9110846700");
    std::cout << s;
  }

  huge_uint pow(unsigned n, unsigned p) {
    huge_uint res{1};
    for (unsigned i = 0; i < p; i++)
      res *= n;
    return res;
  }
};

int main() {
  Problem prob;
  //   prob.solution(10);
  prob.solution(1000);
}
