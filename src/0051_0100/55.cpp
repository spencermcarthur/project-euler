#include "problem.hpp"
#include "util.hpp"

#include <cassert>
#include <iostream>
#include <string>

class Problem : public Problem_<55, Problem> {
  friend class Problem_<55, Problem>;

  void solution_impl(unsigned long) {
    unsigned count{};
    for (unsigned n = 0; n < 10'000; n++) {
      if (is_lychrel(n))
        count++;
    }

    assert(count == 249);
    std::cout << count;
  }

  bool is_lychrel(unsigned n) {
    unsigned long tmp{n}, rev;
    for (int i = 0; i < 50; i++) {
      rev = reverse(tmp);
      tmp = tmp + rev;
      if (is_palindrome(std::to_string(tmp)))
        return false;
    }
    return true;
  }

  unsigned long reverse(unsigned long n) {
    if (n < 10)
      return n;

    unsigned long tmp{};
    while (n > 0) {
      tmp = tmp * 10 + (n % 10);
      n /= 10;
    }

    return tmp;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
