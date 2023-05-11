#include "program.h"

int gcd(int a, int b)
{
  while (a > 0 && b > 0)
  {
    if (a > b)
    {
      a = a % b;
    }
    else
    {
      b = b % a;
    }
  }

  return (a == 0) ? b : a;
}

double fgcd(double a, double b)
{
  if (a < b)
  {
    return fgcd(b, a);
  }

  if (__fabs__(b) < (double)0.001)
  {
    return a;
  }

  return (fgcd(b, a - __floor__(a / b) * b));
}
