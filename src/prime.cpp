#include "prime.hpp"

#include <cmath>
#include <unordered_set>

bool is_prime(unsigned long n) {
  if (n == 1)
    return false;
  else if (n < 4) // 2 and 3
    return true;
  else if (n % 2 == 0) // exclude 4, 6, 8; check all even numbers
    return false;
  else if (n < 9) // 5 and 7 left
    return true;
  else if (n % 3 == 0) // check divisibility by 3
    return false;

  const unsigned long ul = std::sqrt(n);
  for (unsigned long d = 5; d <= ul; d += 6) {
    if (n % d == 0)
      return false;
    else if (n % (d + 2) == 0)
      return false;
  }

  return true;
}

std::vector<unsigned long> get_n_primes(unsigned n) {
  if (n == 0)
    return {};
  else if (n == 1)
    return {2};

  std::vector<unsigned long> primes{2};
  primes.reserve(n);

  unsigned long p{3};
  while (primes.size() < n) {
    if (is_prime(p))
      primes.push_back(p);
    p += 2;
  }
  return primes;
}

bool is_prime_memoized(unsigned long n) {
  static std::unordered_set<unsigned long> memo;

  if (memo.find(n) != memo.end())
    return true;

  if (is_prime(n)) {
    memo.insert(n);
    return true;
  }

  return false;
}

std::vector<bool> sieve(unsigned long n) {
  if (n == 0)
    return {false};

  std::vector<bool> sieve(n + 1, true);
  sieve[0] = sieve[1] = false;
  for (unsigned long i = 2; i < std::sqrt(n); i++) {
    if (sieve[i]) {
      for (unsigned long j = i * i; j <= n; j += i) {
        sieve[j] = false;
      }
    }
  }
  return sieve;
}