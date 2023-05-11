#include "program.h"

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Compute the shannon entropy function.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array,
 * @return A 64 bit floating-point value.
 */
double entropy(const double *x, const size_t n)
{
  double sum = 0.0;

  for (uint64_t i = 0; i < n; i++)
  {
    sum += x[i] * __log__(x[i]);
  }

  return -sum;
}
