#include "problem.hpp"
#include <cassert>
#include <stdexcept>
#include <string>

class Problem : public Problem_<19, Problem> {
  friend class Problem_<19, Problem>;

  void solution_impl(unsigned long) {
    unsigned dow{1}, count{};
    bool counting{false};
    for (unsigned y = 1900; y <= 2000; y++) {
      for (unsigned m = 1; m <= 12; m++) {
        unsigned days = days_in_month(m, y);
        for (unsigned d = 1; d <= days; d++) {
          if (!counting) {
            if (y == 1901 && m == 1 && d == 1)
              counting = true;
          }

          if (counting) {
            if (dow == 7 && d == 1)
              count++;
          }

          if (++dow == 8)
            dow = 1;
        }
      }
    }

    assert(count == 171);
    std::cout << count;
  }

  bool is_leap_year(unsigned y) {
    if (y % 4 != 0)
      return false;

    if (y % 100 == 0)
      return (y % 400 == 0);

    return true;
  }

  unsigned days_in_month(unsigned m, unsigned y) {
    switch (m) {
    default:
      throw std::runtime_error("Invalid month " + std::to_string(m));
    case 4:  // apr
    case 6:  // jun
    case 9:  // sep
    case 11: // nov
      return 30;
    case 1:  // jan
    case 3:  // mar
    case 5:  // may
    case 7:  // jul
    case 8:  // aug
    case 10: // oct
    case 12: // dec
      return 31;
    case 2: // feb
      return (is_leap_year(y) ? 29 : 28);
    }
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
