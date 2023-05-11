#include "common.h"
#include "program.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __internal_tanh__(const double x)
{
  const double n = __exp__( x);
  const double m = __exp__(-x);
  return (n - m) / (n + m);
}

/**
 * @brief Compute the hyperbolic tangent function.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __tanh__(const double x)
{
  return __internal_tanh__(x);
}

/**
 * @brief Compute the hyperbolic tangent of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_tanh(double *x, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __internal_tanh__(x[i]);
  }
}
