#include "program.h"

#include <stddef.h>

/**
 * @brief Compute the skew of a vetor of 64 bit floating-point scalar values.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A integer value. If value is 0 than the array is uniformly
 *         distributed. If the value is 1 than the array has a right
 *         skew and if the value is -1 than the array has a left skew.
 */
int skew(const vector_t *vx)
{
  const double _median = median(vx);
  const double mean = avg(vx);

  if (mean == _median)
  {
    return 0;
  }

  if (mean > _median)
  {
    return 1;
  }

  return (-1);
}
