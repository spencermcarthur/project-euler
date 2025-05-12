#include "problem.hpp"
#include "util.hpp"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#ifndef INPUT_DIR
#pragma GCC error("No input directory")
#endif

class Problem : public Problem_<89, Problem> {
  friend class Problem_<89, Problem>;

  std::vector<std::string> roman;
  const std::map<char, unsigned> values{{'I', 1},   {'V', 5},   {'X', 10},
                                        {'L', 50},  {'C', 100}, {'D', 500},
                                        {'M', 1000}};

public:
  Problem() { load_input(); }

private:
  void solution_impl(unsigned long) {
    unsigned saved{};
    for (const std::string &s : roman)
      saved += s.size() - decimal_to_roman(roman_to_decimal(s)).size();

    assert(saved == 743);
    std::cout << saved;
  }

  void load_input() {
    // Open file
    std::filesystem::path filename(INPUT_DIR);
    filename /= "0089_roman.txt";

    std::ifstream fin(filename);
    if (!fin)
      throw std::runtime_error("Can't load file " + filename.string());

    std::string line;
    while (std::getline(fin, line))
      roman.push_back(line);
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
