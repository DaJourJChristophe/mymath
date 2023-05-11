#include "program.h"
#include "vector.h"

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Compute the arithmetic mean.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t AM(const vector_t *vx)
{
  const scalar_t   n = vx->size;
  const scalar_t sum = vc_sum(vx);
  return sum / n;
}

/**
 * @brief Compute the geometric mean.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t GM(const vector_t *vx)
{
  const scalar_t       n = vx->size;
  const scalar_t product = vc_product(vx);
  return __pow__(product, ((scalar_t)1.0 / n));
}

/**
 * @brief Compute the harmonic mean.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array,
 * @return A 64 bit floating-point value.
 */
double HM(const double *x, const size_t n)
{
  double sum = 0.0;

  for (uint64_t i = 0; i < n; i++)
  {
    sum += (double)1.0 / x[i];
  }

  return (double)n / sum;
}

/**
 * @brief Compute the average of a vector of 64 bit
 *        floating-point scalar values.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t avg(const vector_t *vx)
{
  return AM(vx);
}
