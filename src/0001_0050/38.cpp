#include "problem.hpp"
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

class Problem : public Problem_<38, Problem> {
  friend class Problem_<38, Problem>;

  void solution_impl(unsigned long) {
    unsigned max{};
    for (unsigned i = 192; i < 10'000; i++) {
      std::string s;

      unsigned n{1};
      while (s.size() < 9)
        s += std::to_string(i * n++);

      if (is_pandigital(s)) {
        unsigned n = std::stoul(s);
        if (n > max) {
          max = n;
        }
      }
    }

    assert(max == 932718654);
    std::cout << max;
  }

  bool is_pandigital(const std::string &s) {
    if (s.size() != 9)
      return false;

    std::unordered_map<char, unsigned> freq;
    for (char c : s)
      if (++freq[c] > 1 || c == '0')
        return false;

    return true;
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
