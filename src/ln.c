#include "common.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __ln__(const double x)
{
  double a = 0.0;
  double b = (x - 1) / (x + 1);
  double c = b * b;
  double d = 1.0;
  double f = b;
  double h = f;

  while (h != a)
  {
    a = h;
    d = d + (double)2.0;
    f = f * c;
    h = h + (f / d);
  }

  return (double)2.0 * h;
}

/**
 * @brief Take the natural log of a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double ln(const double x)
{
  return __ln__(x);
}

/**
 * @brief Compute the natural log of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_ln(double *x, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __ln__(x[i]);
  }
}
