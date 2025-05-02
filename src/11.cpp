#include "problem.hpp"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <vector>

#ifndef INPUT_DIR
#pragma GCC error("No input directory")
#endif

class Problem : public Problem_<11, Problem> {
  friend class Problem_<11, Problem>;

  void solution_impl(unsigned long) {
    load_input();

    unsigned maxProd{}, prod;
    const unsigned m = input.size(), n = input[0].size();
    for (unsigned i = 0; i < input.size(); i++) {
      for (unsigned j = 0; j < input[0].size(); j++) {
        bool hasSpaceHoriz = j < n - 4;
        bool hasSpaceVert = i < m - 4;

        // Horizontal
        if (hasSpaceHoriz) {
          prod =
              input[i][j] * input[i][j + 1] * input[i][j + 2] * input[i][j + 3];
          if (prod > maxProd)
            maxProd = prod;
        }

        // Vertical
        if (hasSpaceVert) {
          prod =
              input[i][j] * input[i + 1][j] * input[i + 2][j] * input[i + 3][j];
          if (prod > maxProd)
            maxProd = prod;
        }

        if (hasSpaceHoriz && hasSpaceVert) {
          // Top left - bottom right
          prod = input[i][j] * input[i + 1][j + 1] * input[i + 2][j + 2] *
                 input[i + 3][j + 3];
          if (prod > maxProd)
            maxProd = prod;

          // Bottom left - top right
          prod = input[i + 3][j] * input[i + 2][j + 1] * input[i + 1][j + 2] *
                 input[i][j + 3];
          if (prod > maxProd)
            maxProd = prod;
        }
      }
    }

    assert(maxProd == 70600674);
    std::cout << maxProd;
  }

  void load_input() {
    std::filesystem::path filename(INPUT_DIR);
    filename /= "numbers_0011.txt";

    std::ifstream fin(filename);
    if (!fin)
      throw std::runtime_error("Can't load file " + filename.string());

    std::string line;
    while (std::getline(fin, line)) {
      std::stringstream ss(line);
      std::vector<unsigned> row;
      unsigned n;
      while (ss >> n)
        row.push_back(n);
      input.push_back(row);
    }
  }

  std::vector<std::vector<unsigned>> input;
};

int main() {
  Problem prob;
  prob.solution(0);
}