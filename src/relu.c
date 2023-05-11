#include "common.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __relu__(const double x)
{
  return (x > (double)0.0) ? x : (double)0.0;
}

/**
 * @brief Compute the rectified linear unit function.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double relu(const double x)
{
  return __relu__(x);
}

/**
 * @brief Compute the rectified linear unit of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_relu(double *x, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __relu__(x[i]);
  }
}
