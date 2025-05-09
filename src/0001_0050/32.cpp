#include "problem.hpp"
#include <cassert>
#include <set>
#include <string>
#include <unordered_map>

class Problem : public Problem_<32, Problem> {
  friend class Problem_<32, Problem>;

  void solution_impl(unsigned long) {
    std::set<unsigned> products;
    unsigned prod;
    for (unsigned i = 1; i < 100; i++) {
      for (unsigned j = 1; j < 2000; j++) {
        prod = i * j;
        if (is_pandigital(std::to_string(i) + std::to_string(j) +
                          std::to_string(prod)))
          products.insert(prod);
      }
    }

    unsigned sum{};
    for (unsigned p : products)
      sum += p;

    assert(sum == 45228);
    std::cout << sum;
  }

  bool is_pandigital(const std::string &s) {
    if (s.size() != 9)
      return false;

    std::unordered_map<int, int> freq;
    for (char c : s) {
      if (++freq[c - '0'] > 1 || c == '0')
        return false;
    }

    return true;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
