#pragma once

#include <string>

unsigned long count_divisors(unsigned long n);

void trim_leading(std::string &s, char c);
void trim_trailing(std::string &s, char c);

bool dbl_equal(const double &x, const double &y);

// Szudzik pairing and unpairing functions
unsigned long pair(unsigned x, unsigned y);
std::pair<unsigned, unsigned> unpair(unsigned long z);

bool is_palindrome(const std::string &);

bool is_integral(double);
