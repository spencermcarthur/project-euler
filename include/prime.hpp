#pragma once

#include <vector>

bool is_prime(unsigned long n);

std::vector<unsigned long> get_n_primes(unsigned n);

bool is_prime_memoized(unsigned long n);

std::vector<bool> sieve(unsigned long n);
