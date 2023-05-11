#include <stdint.h>

/**
 * @brief Raise the Euler constant to a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __exp__(const double x)
{
  double y = 1.0;
  double w = 100.0;

  for (uint32_t i = 100; i > 0; --i)
  {
    y = (double)1.0 + x * y * ((double)1.0 / w);
    w = w - (double)1.0;
  }

  return y;
}