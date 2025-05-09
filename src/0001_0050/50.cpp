#include "prime.hpp"
#include "problem.hpp"

#include <cassert>
#include <cstddef>
#include <iostream>
#include <unordered_set>
#include <vector>

class Problem : public Problem_<50, Problem> {
  friend class Problem_<50, Problem>;

  // There are 78,498 primes below 1 million
  static constexpr unsigned n_primes{78'498};
  const std::vector<unsigned long> primes_vec;
  const std::unordered_set<unsigned long> prime_table;

public:
  Problem()
      : primes_vec(get_n_primes(n_primes)),
        prime_table(primes_vec.begin(), primes_vec.end()) {}

private:
  unsigned max_length_sequence{}, argmax{};
  size_t i{}, j{}, sum{primes_vec[j++]};

  void solution_impl(unsigned long n) {
    while (j < primes_vec.size() && i < j) {
      while (sum + primes_vec[j] < n) {
        sum += primes_vec[j++];
        check(sum);
      }

      sum -= primes_vec[i++];
      check(sum);
    }

    assert(argmax == 997651);
    std::cout << argmax;
  }

  void check(size_t sum) {
    if (is_prime_local(sum)) {
      if (j - i > max_length_sequence) {
        max_length_sequence = j - i;
        argmax = sum;
      }
    }
  }

  bool is_prime_local(unsigned n) {
    return prime_table.find(n) != prime_table.end();
  }
};

int main() {
  Problem prob;
  //   prob.solution(100);
  //   prob.solution(1'000);
  prob.solution(1'000'000);
}
