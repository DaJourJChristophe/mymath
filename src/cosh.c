#include "common.h"
#include "program.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __internal_cosh__(const double x)
{
  const double n = 0.5;
  return n * (__exp__(x) + __exp__(-x));
}

/**
 * @brief Compute the hyperbolic cosine function.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __cosh__(const double x)
{
  return __internal_cosh__(x);
}

/**
 * @brief Compute the hyperbolic cosine of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_cosh(double *x, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __internal_cosh__(x[i]);
  }
}
