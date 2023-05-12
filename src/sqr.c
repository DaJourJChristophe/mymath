#include "common.h"
#include "program.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __internal_sqr__(const double x)
{
  return x * x;
}

/**
 * @brief Take the square a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __sqr__(const double x)
{
  return __internal_sqr__(x);
}

/**
 * @brief Take the square a vector value.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_sqr(double *x, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __internal_sqr__(x[i]);
  }
}
