#include "common.h"
#include "program.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __internal_log2__(const double x)
{
  const double n = 2.0;
  return logbase(x, n);
}

/**
 * @brief Take the logarithm base two of a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __log2__(const double x)
{
  return __internal_log2__(x);
}

/**
 * @brief Compute the logarithm base two of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_log2(double *x, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __internal_log2__(x[i]);
  }
}
