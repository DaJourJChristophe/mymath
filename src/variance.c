#include "common.h"
#include "program.h"
#include "scalar.h"
#include "vector.h"

#include <stddef.h>
#include <stdint.h>

static inline scalar_t always_inline variance_prefix(const vector_t *vx)
{
  const size_t    n = vx->size;
  const scalar_t *x = vx->data;
  const double mean = avg(vx);
  double sum = 0.0;

  for (uint64_t i = 0; i < n; i++)
  {
    sum += __pow__((x[i] - mean), (double)2.0);
  }

  return sum;
}

/**
 * @brief Calculate the population variance.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t population_variance(const vector_t *vx)
{
  const scalar_t   n = vx->size;
  const scalar_t sum = variance_prefix(vx);
  return sum / n;
}

/**
 * @brief Calculate the sample variance.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t sample_variance(const vector_t *vx)
{
  const scalar_t   n = vx->size;
  const scalar_t sum = variance_prefix(vx);
  return sum / (n - (scalar_t)1.0);
}
