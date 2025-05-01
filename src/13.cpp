#include "problem.hpp"

#include <boost/multiprecision/cpp_int.hpp>
#include <filesystem>
#include <fstream>
#include <string>

#ifndef INPUT_DIR
#pragma GCC error("No input directory")
#endif

namespace mp = boost::multiprecision;
using LongNum = mp::uint256_t;

class Problem : public Problem_<13, Problem> {
  friend class Problem_<13, Problem>;

  void solution_impl(unsigned long) {
    load_input();
    LongNum res{};
    for (const LongNum &n : input_)
      res += n;
    std::cout << mp::to_string(res).substr(0, 10);
  }

  void load_input() {
    std::filesystem::path filename(INPUT_DIR);
    filename /= "numbers_0013.txt";

    std::ifstream fin(filename);
    if (!fin)
      throw std::runtime_error("Can't load file " + filename.string());

    std::string line;
    while (std::getline(fin, line))
      input_.emplace_back(line);
  }

  std::vector<LongNum> input_;
};

int main() {
  Problem prob;
  prob.solution(0);
}
