#include "input.hpp"
#include "poker.hpp"
#include "problem.hpp"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#ifndef INPUT_DIR
#pragma GCC error("No input directory")
#endif

class Problem : public Problem_<54, Problem> {
  friend class Problem_<54, Problem>;

public:
  Problem() { load_input(); }

private:
  void solution_impl(unsigned long) {
    unsigned count{};
    for (const auto &[h1, h2] : hands_) {
      if (player1_wins(h1, h2))
        count++;
    }

    std::cout << count;
  }

  bool player1_wins(const Hand &h1, const Hand &h2) {
    if (h1.type() > h2.type())
      return true;
    else if (h1.type() == h2.type()) {
      // Check kickers
    }

    return false;
  }

  std::vector<std::pair<Hand, Hand>> hands_;
  void load_input() {
    std::filesystem::path filename(INPUT_DIR);
    filename /= "0054_poker.txt";

    std::ifstream fin(filename);
    if (!fin)
      throw std::runtime_error("Can't load file " + filename.string());

    std::string line;
    while (std::getline(fin, line)) {
      // Split line
      std::vector<std::string> line_split = split(line, " ");
      assert(line_split.size() == 10);

      // Parse cards
      Hand h1, h2;
      for (size_t i = 0; i < 10; i++) {
        if (i < 5)
          h1.add_card(Card(line_split[i]));
        else
          h2.add_card(Card(line_split[i]));
      }

      hands_.push_back({h1, h2});
    }

    assert(hands_.size() == 1000);
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
