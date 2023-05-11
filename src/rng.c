#include "program.h"

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Compute the range function.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array,
 * @return A 64 bit floating-point value.
 */
double rng(const double *x, const size_t n)
{
  double max = -INF;
  double min =  INF;

  for (uint64_t i = 0; i < n; i++)
  {
    if (x[i] > max)
    {
      max = x[i];
    }
    if (x[i] < min)
    {
      min = x[i];
    }
  }

  return max - min;
}
