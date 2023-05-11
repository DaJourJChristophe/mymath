#include "program.h"
#include "scalar.h"
#include "wrapper.h"

#include <benchmark/benchmark.h>
#include <math.h>
#include <string.h>

static void BM_NaiveScalarExpTest(benchmark::State& state)
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
      exp(x);
    }
  }
}

static void BM_ScalarExpTest(benchmark::State& state)
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
      __exp__(x);
    }
  }
}

BENCHMARK(BM_NaiveScalarExpTest);

BENCHMARK(BM_ScalarExpTest);

BENCHMARK_MAIN();
