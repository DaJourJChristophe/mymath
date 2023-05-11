#include "common.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __cub__(const double x)
{
  return x * x * x;
}

/**
 * @brief Take the cube a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double cub(const double x)
{
  return __cub__(x);
}

/**
 * @brief Compute the cube of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_cub(double *x, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __cub__(x[i]);
  }
}
