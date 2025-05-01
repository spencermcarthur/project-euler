#pragma once

#include <string>
#include <vector>

static std::vector<std::string> split(const std::string &s,
                                      const std::string delim = ",") {
  std::vector<std::string> res;

  size_t i{0}, j{0};
  while (j != std::string::npos) {
    j = s.find_first_of(delim, i);
    res.emplace_back(s.substr(i, j - i));
    i = j + 1;
  }

  return res;
}
