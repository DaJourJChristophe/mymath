#include "common.h"
#include "matrix.h"
#include "program.h"

#include <stdio.h>
#include <stdlib.h>

void solve(const char *s)
{
  for (; *s; s++)
  {
    printf("%c", *s);
  }
  printf("\n");
}

int main(void)
{
  matrix_t *mx = mx_random(4, 5);

  mx_add(mx, 1);
  mx_print(mx);

  mx_mul(mx, 1);
  mx_print(mx);

  mx_div(mx, 1);
  mx_print(mx);

  mx_sub(mx, 1);
  mx_print(mx);

  mx_destroy(mx);

  return EXIT_SUCCESS;
}
