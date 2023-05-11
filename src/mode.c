#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

static void sort(double *x, const ssize_t n)
{
  double key;
  int64_t i;
  int64_t j;

  for (i = 1; i < n; i++)
  {
    key = x[i];
    j = i - 1;

    while (j >= 0 && x[j] > key)
    {
      x[j + 1] = x[j];
      j = j - 1;
    }

    x[j + 1] = key;
  }
}

double mode(double *x, const size_t n)
{
  sort(x, n);

  double number = x[0];
  double mode = number;

  uint64_t count = 1;
  uint64_t countMode = 1;

  for (uint64_t i = 1; i < n; i++)
  {
    if (x[i] == number)
    {
      ++count;
      continue;
    }

    if (count > countMode)
    {
      countMode = count;
      mode = number;
    }

    count = 1;
    number = x[i];
  }

  return mode;
}
