#include "problem.hpp"

#include <unordered_map>

class Problem : public Problem_<17, Problem> {
  friend class Problem_<17, Problem>;

  void solution_impl(unsigned long n) {
    unsigned long sum{};
    for (unsigned i = 1; i <= n; i++)
      sum += count_letters(i);

    std::cout << sum;
  }

  unsigned count_letters(unsigned n) {
    if (n == 0)
      return 0;

    if (lookup.find(n) != lookup.end())
      return lookup.at(n).size();

    if (n < 100) {
      unsigned mod = n % 10;
      // E.g. 85: eighty + 5
      return count_letters(n - mod) + count_letters(mod);
    } else if (n < 1000) {
      unsigned mod = n % 100;
      unsigned hundreds = count_letters(n / 100) + 7 /*hundred*/;
      unsigned tens = count_letters(mod);
      return hundreds + tens + ((tens == 0) ? 0 : 3 /*and*/);
    } else
      return 11 /*onethousand*/;
  }

  const std::unordered_map<unsigned, std::string> lookup{
      {1, "one"},        {2, "two"},       {3, "three"},     {4, "four"},
      {5, "five"},       {6, "six"},       {7, "seven"},     {8, "eight"},
      {9, "nine"},       {10, "ten"},      {11, "eleven"},   {12, "twelve"},
      {13, "thirteen"},  {14, "fourteen"}, {15, "fifteen"},  {16, "sixteen"},
      {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"}, {20, "twenty"},
      {30, "thirty"},    {40, "forty"},    {50, "fifty"},    {60, "sixty"},
      {70, "seventy"},   {80, "eighty"},   {90, "ninety"},
  };
};

int main() {
  Problem prob;
  //   prob.solution(5);
  prob.solution(1000);
}
