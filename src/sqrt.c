#include "common.h"
#include "program.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __internal_sqrt__(const double x)
{
  const double n = 2.0;
  return root(x, n);
}

/**
 * @brief Take the square root of a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __sqrt__(const double x)
{
  return __internal_sqrt__(x);
}

/**
 * @brief Take the square root of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_sqrt(double *x, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __internal_sqrt__(x[i]);
  }
}
