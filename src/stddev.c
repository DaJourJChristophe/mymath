#include "program.h"

/**
 * @brief Calculate the standard deviation function.
 * @param variance A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double stddev(const double variance)
{
  return __sqrt__(variance);
}
