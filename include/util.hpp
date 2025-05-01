#pragma once

#include <cmath>
#include <unordered_map>

static unsigned long count_divisors(unsigned long n) {
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
