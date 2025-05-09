#include "input.hpp"
#include "problem.hpp"

#include <array>
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
  std::string alphabet;
  using key_t = std::array<char_t, key_size>;

  std::vector<char_t> encrypted;
  std::vector<key_t> keys;

public:
  Problem() {
    // Generate alphabet
    for (char_t c = 'a'; c <= 'z'; c++)
      alphabet += c;

    load_input();
    generate_keys();
  }

private:
  void solution_impl(unsigned long) {
    std::vector<char_t> decrypted;
    bool found{false};
    for (const key_t &key : keys) {
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

    if (c >= '0' && c <= '9')
      return true;
    else if (c >= 'A' && c <= 'Z')
      return true;
    else if (c >= 'a' && c <= 'z')
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

  void generate_keys() {
    unsigned num_keys{1};
    for (unsigned i = 0; i < key_size; i++)
      num_keys *= alphabet.size();
    keys.reserve(num_keys);

    gen_keys_recursive(alphabet.size(), key_size, 0, {});
  }

  void gen_keys_recursive(unsigned n, unsigned k, unsigned curr_idx,
                          std::array<char_t, key_size> key_array) {
    if (curr_idx == k) {
      keys.push_back(key_array);
      return;
    }

    for (unsigned x = 0; x < n; x++) {
      key_array[curr_idx] = 'a' + x;
      gen_keys_recursive(n, k, curr_idx + 1, key_array);
    }
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
