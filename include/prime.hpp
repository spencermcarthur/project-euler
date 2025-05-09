#pragma once

#include <set>
#include <unordered_set>
#include <vector>

bool is_prime(unsigned long n);

std::vector<unsigned long> get_n_primes(unsigned n);
std::set<unsigned long> get_n_primes_set(unsigned n);
std::unordered_set<unsigned long> get_n_primes_uset(unsigned n);

bool is_prime_memoized(unsigned long n);

std::vector<bool> sieve(unsigned long n);
