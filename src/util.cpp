#include "util.hpp"

#include <cmath>
#include <unordered_map>

unsigned long count_divisors(unsigned long n) {
  if (n == 1)
    return n;

  std::unordered_map<unsigned long, bool> divisors{{1, true}, {n, true}};
  for (unsigned long d = 2; d <= std::sqrt(n); d++) {
    if (divisors.find(d) != divisors.end())
      continue;

    if (n % d == 0) {
      divisors[d] = true;
      divisors[n / d] = true;
    }
  }

  return divisors.size();
}

void trim_leading(std::string &s, char c) {
  size_t i{};
  while (s[i] == c)
    i++;
  s = s.substr(i);
}

void trim_trailing(std::string &s, char c) {
  size_t i{s.size() - 1};
  while (s[i] == c)
    i--;
  s = s.substr(0, i + 1);
}
