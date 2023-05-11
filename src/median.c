#include "scalar.h"
#include "vector.h"

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Compute the mean of a vector of 64 bit floating-point scalar values.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t median(const vector_t *vx)
{
  const size_t    n = vx->size;
  const scalar_t *x = vx->data;

  uint64_t lt;
  uint64_t eq;

  uint64_t i;
  uint64_t j;

  for (i = 0; i < n; i++)
  {
    lt = 0;
    eq = 0;

    for (j = 0; j < n; j++)
    {
      if (i == j)
      {
        continue;
      }

      if (x[j] < x[i])
      {
        lt++;
      }
      else if (x[j] == x[i])
      {
        eq++;
      }
    }

    if ((n - (scalar_t)1.0) / (scalar_t)2.0 >= lt &&
        (n - (scalar_t)1.0) / (scalar_t)2.0 <= (lt + eq))
    {
      return x[i];
    }
  }

  return (scalar_t)0.0;
}
