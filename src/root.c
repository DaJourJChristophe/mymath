#include "common.h"
#include "program.h"

#include <stddef.h>
#include <stdint.h>

static inline double always_inline __root__(const double x, const double n)
{
  return __exp__(__log__(x) / n);
}
/**
 * @brief Take the nth root of a floating-point value and a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double root(const double x, const double n)
{
  return __root__(x, n);
}

/**
 * @brief Take the nth root of a vector and a floating-point value.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_root(double *x, const double nth, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __root__(x[i], nth);
  }
}
