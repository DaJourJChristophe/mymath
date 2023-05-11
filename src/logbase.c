#include "common.h"
#include "program.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __logbase__(const double x, const double base)
{
  return __log10__(x) / __log10__(base);
}

/**
 * @brief Take the logarithm base of a floating-point value and a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double logbase(const double x, const double base)
{
  return __logbase__(x, base);
}

/**
 * @brief Compute the logarithm base of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_logbase(double *x, const double base, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __logbase__(x[i], base);
  }
}
