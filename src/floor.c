#include "common.h"
#include "program.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __internal_floor__(const double x)
{
  return (double)((int)(x));
}

double __floor__(const double x)
{
  return __internal_floor__(x);
}

/**
 * @brief Compute the sum of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_floor(double *x, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __internal_floor__(x[i]);
  }
}
