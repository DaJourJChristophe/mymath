#include "program.h"
#include "scalar.h"
#include "wrapper.h"

#include <benchmark/benchmark.h>
#include <string.h>

static double naive_cub(const double x)
{
  return x * x * x;
}

static void BM_NaiveScalarCubTest(benchmark::State& state)
{
  const scalar_t epsilon = EPSILON;
  const scalar_t n       = MAX_TEST_DEPTH;
        scalar_t x       = MIN_TEST_DEPTH;

  scalar_t buffer[MAX_ITEMS_TEST];
  memset(buffer, 0, (MAX_ITEMS_TEST * sizeof(scalar_t)));

  for (auto _ : state)
  {
    for (uint64_t i = 0; i < MAX_ITEMS_TEST && x < n; x += epsilon, i++)
    {
      naive_cub(x);
    }
  }
}

static void BM_ScalarCubTest(benchmark::State& state)
{
  const scalar_t epsilon = EPSILON;
  const scalar_t n       = MAX_TEST_DEPTH;
        scalar_t x       = MIN_TEST_DEPTH;

  scalar_t buffer[MAX_ITEMS_TEST];
  memset(buffer, 0, (MAX_ITEMS_TEST * sizeof(scalar_t)));

  for (auto _ : state)
  {
    for (uint64_t i = 0; i < MAX_ITEMS_TEST && x < n; x += epsilon, i++)
    {
      cub(x);
    }
  }
}

BENCHMARK(BM_NaiveScalarCubTest);

BENCHMARK(BM_ScalarCubTest);

BENCHMARK_MAIN();
