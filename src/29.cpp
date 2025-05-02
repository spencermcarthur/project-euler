#include "problem.hpp"

#include <boost/multiprecision/cpp_int.hpp>
#include <cassert>
#include <set>

using boost::multiprecision::uint1024_t;

class Problem : public Problem_<29, Problem> {
  friend class Problem_<29, Problem>;

  void solution_impl(unsigned long n) {
    std::set<uint1024_t> nums;
    for (uint1024_t a = 2; a <= n; a++) {
      for (uint1024_t b = 2; b <= n; b++) {
        nums.insert(my_pow(a, b));
      }
    }

    assert(nums.size() == 9183);
    std::cout << nums.size();
  }

  uint1024_t my_pow(uint1024_t a, uint1024_t b) {
    uint1024_t res{1};
    for (uint1024_t i = 0; i < b; i++)
      res *= a;

    return res;
  }
};

int main() {
  Problem prob;
  //   prob.solution(5);
  prob.solution(100);
}
