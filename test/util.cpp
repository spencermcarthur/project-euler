#include <chrono>
#include <gtest/gtest.h>
#include <limits>
#include <random>

#include "util.hpp"

void pairing_test_case(unsigned a, unsigned b) {
  unsigned long z = pair(a, b);
  auto [ap, bp] = unpair(z);

  EXPECT_EQ(a, ap);
  EXPECT_EQ(b, bp);
}

TEST(Pairing, PairUnpair) {
  pairing_test_case(0, 0);
  pairing_test_case(std::numeric_limits<unsigned>::max(),
                    std::numeric_limits<unsigned>::max());

  std::uniform_int_distribution<unsigned> dist;
  std::default_random_engine rng;
  rng.seed(
      std::chrono::high_resolution_clock::now().time_since_epoch().count());

  for (int i = 0; i < 1'000'000; i++)
    pairing_test_case(dist(rng), dist(rng));
}
