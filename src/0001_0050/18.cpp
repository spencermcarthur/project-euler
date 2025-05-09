#include "problem.hpp"

#include <algorithm>
#include <cassert>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#ifndef INPUT_DIR
#pragma GCC error("No input directory")
#endif

class Problem : public Problem_<18, Problem> {
  friend class Problem_<18, Problem>;

  void solution_impl(unsigned long) {
    load_input();

    std::reverse(input.begin(), input.end());
    for (size_t i = 1; i < input.size(); i++) {
      for (size_t j = 0; j < input[i].size(); j++) {
        input[i][j] += std::max(input[i - 1][j], input[i - 1][j + 1]);
      }
    }

    assert(input.back()[0] == 1074);
    std::cout << input.back()[0];
  }

  std::vector<std::vector<int>> input;
  void load_input() {
    std::filesystem::path filename(INPUT_DIR);
    filename /= "0018_triangle.txt";

    std::ifstream fin(filename);
    if (!fin)
      throw std::runtime_error("Can't load file " + filename.string());

    std::string line;
    while (std::getline(fin, line)) {
      std::vector<int> row;
      std::stringstream ss(line);
      int n;
      while (ss >> n)
        row.push_back(n);
      input.push_back(row);
    }
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
