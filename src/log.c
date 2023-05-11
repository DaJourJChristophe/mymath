#include "common.h"
#include "program.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __internal_log__(const double x)
{
  return logbase(x, E);
}

/**
 * @brief Take the logarithm of a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __log__(const double x)
{
  return __internal_log__(x);
}

/**
 * @brief Compute the logarithm of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_log(double *x, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __internal_log__(x[i]);
  }
}
