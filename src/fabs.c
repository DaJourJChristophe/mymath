#include "common.h"

#include <stddef.h>
#include <stdint.h>

#define L63M (uint64_t)0x7fffffffffffffff

#define L63(x) \
  x & L63M

#define U64(x) \
  *(uint64_t *)&x

#define P64(x) \
  &(uint64_t){x}

#define F64(x) \
  *(double *)(x)

static inline double always_inline __internal_fabs__(const double x)
{
  return F64(P64(L63(U64(x))));
}

/**
 * @brief Take the absolute value of a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __fabs__(const double x)
{
  return __internal_fabs__(x);
}

/**
 * @brief Compute the absolute value of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_fabs(double *x, const size_t n)
{
  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __internal_fabs__(x[i]);
  }
}
