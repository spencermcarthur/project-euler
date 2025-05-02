#include "problem.hpp"
#include <cassert>

class Problem : public Problem_<4, Problem> {
  friend class Problem_<4, Problem>;

  void solution_impl(unsigned long) {
    unsigned long largest_palindromic_product{0}, prod;
    for (unsigned long i = 999; i > 0; i--) {
      for (unsigned long j = 999; j > 0; j--) {
        prod = i * j;
        if (is_palindromic(prod) && prod > largest_palindromic_product)
          largest_palindromic_product = prod;
      }
    }

    assert(largest_palindromic_product == 906609);
    std::cout << largest_palindromic_product;
  }

  bool is_palindromic(unsigned long n) {
    unsigned long tmp = n, m{0};
    while (tmp > 0) {
      m = m * 10 + (tmp % 10);
      tmp /= 10;
    }
    return n == m;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}