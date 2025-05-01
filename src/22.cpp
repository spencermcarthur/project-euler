#include "input.hpp"
#include "problem.hpp"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

#ifndef INPUT_DIR
#pragma GCC error("No input directory")
#endif

class Problem : public Problem_<22, Problem> {
  friend class Problem_<22, Problem>;

  void solution_impl(unsigned long) {
    load_input();

    std::sort(names.begin(), names.end());
    unsigned long sum{};
    for (size_t i = 0; i < names.size(); i++) {
      unsigned nameSum{};
      for (char c : names[i])
        nameSum += (c - 'A' + 1);
      sum += nameSum * (i + 1);
    }

    std::cout << sum;
  }

  std::vector<std::string> names;
  void load_input() {
    std::filesystem::path filename(INPUT_DIR);
    filename /= "names_0022.txt";

    std::ifstream fin(filename);
    if (!fin)
      throw std::runtime_error("Can't load file " + filename.string());

    std::string s;
    std::getline(fin, s);

    names = split(s);
    for (std::string &s : names) {
      s.erase(0, 1);
      s.erase(s.size() - 1, 1);
    }
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
