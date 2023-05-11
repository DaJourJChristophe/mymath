#include "program.h"

#include <stddef.h>

/**
 * @brief Calculate the standard error of the mean.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t SEM(const vector_t *vx)
{
  const scalar_t n = vx->size;
  return stddev(population_variance(vx)) / __sqrt__(n);
}
