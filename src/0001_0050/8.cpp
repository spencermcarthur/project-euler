#include "problem.hpp"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>

#ifndef INPUT_DIR
#pragma GCC error("No input directory")
#endif

class Problem : public Problem_<8, Problem> {
  friend class Problem_<8, Problem>;

  void solution_impl(unsigned long n) {
    load_input();

    unsigned long prod, maxProd{0};

    for (unsigned i = 0; i < input.size(); i++) {
      prod = 1;
      for (unsigned j = 0; j < n; j++)
        prod *= input[i + j] - '0';
      if (prod > maxProd)
        maxProd = prod;
    }

    assert(maxProd == 23514624000);
    std::cout << maxProd;
  }

  void load_input() {
    std::filesystem::path filename(INPUT_DIR);
    filename /= "0008_digits.txt";

    std::ifstream fin(filename);
    if (!fin)
      throw std::runtime_error("Can't load file " + filename.string());

    std::string line;
    while (std::getline(fin, line))
      input += line;
  }

  std::string input;
};

int main() {
  Problem prob;
  //   prob.solution(4);
  prob.solution(13);
}