#include "util.hpp"

#include <cassert>
#include <cmath>
#include <limits>
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

bool dbl_equal(const double &x, const double &y) {
  return std::abs(x - y) < std::numeric_limits<double>::epsilon();
}

unsigned long pair(unsigned x, unsigned y) {
  unsigned long z = x;

  if (x < y)
    z += (unsigned long)y * (unsigned long)y;
  else
    z += (unsigned long)x * (unsigned long)x + (unsigned long)y;

  return z;
}

// Required because std::sqrt casts to double, which does not have the precision
// to take the sqrt of large unsigned long values accurately
unsigned floor_sqrt(unsigned long x) {
  if (x == 0)
    return 0;
  else if (x == std::numeric_limits<unsigned long>::max())
    return std::numeric_limits<unsigned>::max();

  unsigned long l{0}, r{std::numeric_limits<unsigned>::max()}, m;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (m * m < x)
      l = m;
    else
      r = m;
  }
  return l;
}

std::pair<unsigned, unsigned> unpair(unsigned long z) {
  unsigned long floor_sqrt_z = floor_sqrt(z);
  unsigned long floor_sqrt_z_squared = floor_sqrt_z * floor_sqrt_z;
  unsigned long a = z - floor_sqrt_z_squared;
  return (a < floor_sqrt_z)
             ? std::pair<unsigned, unsigned>{a, floor_sqrt_z}
             : std::pair<unsigned, unsigned>{floor_sqrt_z, a - floor_sqrt_z};
}

bool is_palindrome(const std::string &s) {
  if (s.size() == 1)
    return true;

  size_t i{0}, j{s.size() - 1};
  while (i < j) {
    if (s[i] != s[j])
      return false;
    i++;
    j--;
  }

  return true;
}

bool is_integral(double d) {
  double p{};
  d = std::modf(d, &p);
  return d < std::numeric_limits<double>::epsilon();
}
