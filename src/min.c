#include "program.h"

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Find the smallest value in an array of 64 bit floating-point values.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array,
 * @return A 64 bit floating-point value.
 */
double min(const double *x, const size_t n)
{
  double y = x[0];

  for (uint64_t i = 1; i < n; i++)
  {
    if (x[i] >= y)
    {
      continue;
    }

    y = x[i];
  }

  return y;
}
