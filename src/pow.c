#include "common.h"
#include "program.h"

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Raise a floating-point value to a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __pow__(const double x, const double power)
{
  if (x == (double)0.0)
  {
    return 0.0;
  }

  if (power == (double)0.0)
  {
    return (double)1.0;
  }

  else if (power < (double)0.0)
  {
    return (double)1.0 / __pow__(x, __fabs__(power));
  }

  else if (power > (double)0.0 && power < (double)1.0)
  {
    return root(x, __pow__(power, (double)(-1.0)));
  }

  return x * __pow__(x, (power - (double)1.0));
}

/**
 * @brief Raise a vector to a floating-point value.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_pow(double *x, const double power, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __pow__(x[i], power);
  }
}
