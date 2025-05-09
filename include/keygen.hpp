#pragma once

#include <array>
#include <ostream>
#include <string>

template <size_t key_size, typename char_t = unsigned char>
std::ostream &operator<<(std::ostream &os,
                         const std::array<char_t, key_size> &key) {
  for (size_t i = 0; i < key.size(); i++)
    os << key[i];
  return os;
}

template <size_t key_size, typename char_t = unsigned char> class KeyGenerator {
public:
  using key_t = std::array<char_t, key_size>;

  KeyGenerator(const std::string &alphabet) : alphabet_(alphabet) {}

  size_t num_possible_keys() {
    size_t res{1};
    for (size_t i = 0; i < key_size; i++)
      res *= alphabet_.size();
    return res;
  }

  void get_next_key(key_t &key) { get_next_key_recursive(0, key); }

private:
  bool get_next_key_recursive(size_t i, key_t &key) {
    if (i == key_size)
      return true;

    size_t &idx_ = indexes_[i];
    char_t c = alphabet_[idx_];
    key[i] = c;

    if (get_next_key_recursive(i + 1, key)) {
      if (idx_ == alphabet_.size() - 1) {
        idx_ = 0;
        return true;
      } else
        idx_++;
    }

    return false;
  }

  const std::string alphabet_;
  std::array<size_t, key_size> indexes_{};
};
