#include <benchmark/benchmark.h>
#include <chrono>
#include <random>
#include <unordered_map>

#include "util.hpp"

std::uniform_int_distribution<unsigned long> dist;
std::default_random_engine rng;
long seed;

void bm_paired_hash(benchmark::State &s) {
  std::unordered_map<unsigned long, bool> hashmap;
  rng.seed(seed);
  for (auto _ : s)
    hashmap[pair(dist(rng), dist(rng))] = true;

  s.SetItemsProcessed(s.iterations());
}
BENCHMARK(bm_paired_hash);

void bm_separate_hash(benchmark::State &s) {
  std::unordered_map<unsigned, std::unordered_map<unsigned, bool>> hashmap;
  rng.seed(seed);
  for (auto _ : s)
    hashmap[dist(rng)][dist(rng)] = true;

  s.SetItemsProcessed(s.iterations());
}
BENCHMARK(bm_separate_hash);

int main(int argc, char **argv) {
  char arg0_default[] = "benchmark";
  char *args_default = arg0_default;
  if (!argv) {
    argc = 1;
    argv = &args_default;
  }

  seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

  ::benchmark::Initialize(&argc, argv);
  if (::benchmark::ReportUnrecognizedArguments(argc, argv))
    return 1;
  ::benchmark::RunSpecifiedBenchmarks();
  ::benchmark::Shutdown();

  return 0;
}
