#include "common.h"
#include "program.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __sigmoid__(const double x)
{
  return (double)1.0 / ((double)1.0 + __exp__(-x));
}

/**
 * @brief Compute the sigmoid function.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double sigmoid(const double x)
{
  return __sigmoid__(x);
}

/**
 * @brief Compute the sum of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_sigmoid(double *x, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __sigmoid__(x[i]);
  }
}
