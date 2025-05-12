#include "util.hpp"

#include <cassert>
#include <cmath>
#include <limits>
#include <map>
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

unsigned roman_to_decimal(const std::string &s) {
  static const std::map<char, unsigned> values{
      {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
      {'C', 100}, {'D', 500}, {'M', 1000}};

  unsigned value{};
  const size_t len = s.size();

  for (size_t i = 0; i < len; i++) {
    const unsigned &curr = values.at(s[i]);
    if (i < len - 1) {
      const unsigned &next = values.at(s[i + 1]);
      if (curr < next)
        value -= curr;
      else
        value += curr;
    } else
      value += curr;
  }

  return value;
}

std::string decimal_to_roman(unsigned n) {
  std::string s;

  while (n > 0) {
    if (n >= 1000) {
      s += 'M';
      n -= 1000;
    } else if (n >= 900) {
      s += "CM";
      n -= 900;
    } else if (n >= 500) {
      s += 'D';
      n -= 500;
    } else if (n >= 400) {
      s += "CD";
      n -= 400;
    } else if (n >= 100) {
      s += 'C';
      n -= 100;
    } else if (n >= 90) {
      s += "XC";
      n -= 90;
    } else if (n >= 50) {
      s += 'L';
      n -= 50;
    } else if (n >= 40) {
      s += "XL";
      n -= 40;
    } else if (n >= 10) {
      s += 'X';
      n -= 10;
    } else if (n >= 9) {
      s += "IX";
      n -= 9;
    } else if (n >= 5) {
      s += 'V';
      n -= 5;
    } else if (n >= 4) {
      s += "IV";
      n -= 4;
    } else {
      s += 'I';
      n -= 1;
    }
  }

  return s;
}
