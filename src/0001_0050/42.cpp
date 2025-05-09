#include "input.hpp"
#include "problem.hpp"

#include <algorithm>
#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#ifndef INPUT_DIR
#pragma GCC error("No input directory")
#endif

class Problem : public Problem_<42, Problem> {
  friend class Problem_<42, Problem>;

  static constexpr unsigned num_tri{20};
  std::vector<unsigned> tri;

public:
  Problem() {
    load_input();
    tri.reserve(num_tri);
    for (unsigned n = 1; n <= num_tri; n++)
      tri.push_back(n * (n + 1) / 2);
  }

private:
  void solution_impl(unsigned long) {

    unsigned count{};
    for (const std::string &w : words)
      if (is_triangle_word(w))
        count++;

    assert(count == 162);
    std::cout << count;
  }

  bool is_triangle_word(const std::string &w) {
    unsigned sum{};
    for (char c : w)
      sum += c - 'A' + 1;

    // Add more triangle numbers if needed
    while (sum > tri.back()) {
      unsigned n = tri.size() + 1;
      tri.push_back(n * (n + 1) / 2);
    }

    // Linear search okay for short array
    return std::find(tri.begin(), tri.end(), sum) != tri.end();
  }

  std::vector<std::string> words;
  void load_input() {
    std::filesystem::path filename(INPUT_DIR);
    filename /= "0042_words.txt";

    std::ifstream fin(filename);
    if (!fin)
      throw std::runtime_error("Can't load file " + filename.string());

    std::string s;
    std::getline(fin, s);

    words = split(s);
    for (std::string &w : words) {
      w.erase(0, 1);
      w.erase(w.size() - 1);
    }
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
