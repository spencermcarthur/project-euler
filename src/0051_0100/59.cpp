#include "input.hpp"
#include "keygen.hpp"
#include "problem.hpp"

#include <cassert>
#include <cstddef>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#ifndef INPUT_DIR
#pragma GCC error("No input directory")
#endif

class Problem : public Problem_<59, Problem> {
  friend class Problem_<59, Problem>;

  using char_t = unsigned char;
  static constexpr unsigned key_size = 3;
  using keygen_t = KeyGenerator<key_size, char_t>;
  using key_t = keygen_t::key_t;

  const std::string alphabet{"abcdefghijklmnopqrstuvwxyz"};
  keygen_t keygen;

  std::vector<char_t> encrypted;

public:
  Problem() : keygen(alphabet) { load_input(); }

private:
  void solution_impl(unsigned long) {
    std::vector<char_t> decrypted;
    keygen_t::key_t key;
    bool found{false};
    for (size_t i = 0; i < keygen.num_possible_keys(); i++) {
      keygen.get_next_key(key);
      decrypted = decrypt(key);
      if (is_text_valid(decrypted)) {
        found = true;
        break;
      }
    }

    if (!found) {
      std::cout << "Not found";
      return;
    }

    unsigned sum{};
    for (char_t c : decrypted)
      sum += c;

    assert(sum == 129448);
    std::cout << sum;
  }

  bool is_text_valid(const std::vector<char_t> &decrypted) {
    // Frequency analysis for given character set
    double valid{0.0}, total{0.0};
    for (char_t c : decrypted) {
      if (is_char_valid(c))
        valid += 1.0;
      total += 1.0;
    }

    return valid / total > 0.99;
  }

  bool is_char_valid(char_t c) {
    static const std::string punct_chars{" ,./?;:\'\"!()-"};

    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z'))
      return true;
    for (char_t test : punct_chars)
      if (c == test)
        return true;

    return false;
  }

  std::vector<char_t> decrypt(const key_t &key) {
    std::vector<char_t> decrypted(encrypted.size(), 0);
    for (size_t i = 0; i < encrypted.size(); i++)
      decrypted[i] = encrypted[i] ^ key[i % key_size];
    return decrypted;
  }

  void load_input() {
    // Open file
    std::filesystem::path filename(INPUT_DIR);
    filename /= "0059_cipher.txt";

    std::ifstream fin(filename);
    if (!fin)
      throw std::runtime_error("Can't load file " + filename.string());

    // Get line
    std::string line;
    std::getline(fin, line);

    // Parse line
    std::vector<std::string> line_split = split(line);
    encrypted.reserve(line_split.size());
    for (const std::string &s : line_split)
      encrypted.push_back(std::stoul(s));

    assert(encrypted.size() == line_split.size());
  }
};

int main() {
  Problem prob;
  prob.solution(0);
}
