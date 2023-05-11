#include "common.h"
#include "matrix.h"
#include "program.h"

#include <immintrin.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline matrix_t * always_inline __internal_mx_empty__(void)
{
  matrix_t *mx = NULL;
  mx = calloc(1, sizeof(matrix_t));
  return mx;
}

matrix_t *mx_empty(void)
{
  return __internal_mx_empty__();
}

static inline void always_inline __internal_mx_set__(
  matrix_t *mx, const size_t rows, const size_t cols
)
{
  mx->rows = rows;
  mx->cols = cols;
  mx->size = (rows * cols);
}

void mx_set(matrix_t *mx, const size_t rows, const size_t cols)
{
  __internal_mx_set__(mx, rows, cols);
}

matrix_t *mx_new(const scalar_t **data, const size_t rows, const size_t cols)
{
  matrix_t *mx = __internal_mx_empty__();

  __internal_mx_set__(mx, rows, cols);

  if (data == NULL)
  {
    goto done;
  }

  const size_t n = cols + (cols & 1);

  mx->data = calloc((rows + (rows & 1)), sizeof(scalar_t *));

  for (uint64_t i = 0; i < rows; i++)
  {
    mx->data[i] = calloc(n, sizeof(scalar_t));
    memcpy(mx->data[i], data[i], (n * sizeof(scalar_t)));
  }
done:
  return mx;
}

matrix_t *mx_random(const size_t rows, const size_t cols)
{
  matrix_t *mx = __internal_mx_empty__();

  __internal_mx_set__(mx, rows, cols);

  mx->data = calloc((rows + (rows & 1)), sizeof(scalar_t *));

  uint64_t i;
  uint64_t j;

  for (i = 0; i < rows; i++)
  {
    mx->data[i] = calloc((cols + (cols & 1)), sizeof(scalar_t));

    for (j = 0; j < cols; j++)
    {
      mx->data[i][j] = (scalar_t)rand() / (scalar_t)RAND_MAX;
    }
  }

  return mx;
}

void mx_destroy(matrix_t *mx)
{
  const size_t rows = mx->rows;

  for (uint64_t i = 0; i < rows; i++)
  {
    if (mx->data[i] != NULL)
    {
      free(mx->data[i]);
      mx->data[i] = NULL;
    }
  }

  if (mx->data != NULL)
  {
    free(mx->data);
    mx->data = NULL;
  }

  if (mx != NULL)
  {
    free(mx);
    mx = NULL;
  }
}

void mx_add(matrix_t *mx, const scalar_t a)
{
  const size_t     rows = mx->rows;
  const size_t     cols = mx->cols;
        scalar_t **data = mx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  uint64_t i;
  uint64_t j;

  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j += 2)
    {
      va = _mm_load_pd((data[i] + j));
      vb = _mm_set_pd(a, a);

      vc = _mm_add_pd(va, vb);

      data[i][j]   = vc[0];
      data[i][j+1] = vc[1];
    }
  }
}

bool mx_cmp(matrix_t *ma, matrix_t *mb)
{
  return ma == mb && ma->data == mb->data;
}

bool mx_equ(matrix_t *ma, matrix_t *mb)
{
  const size_t   ra = ma->rows;
  const size_t   ca = ma->cols;
        double **da = ma->data;

  const size_t   rb = mb->rows;
  const size_t   cb = mb->cols;
        double **db = mb->data;

  if (ra != rb || ca != cb)
  {
    return false;
  }

  uint64_t i;
  uint64_t j;

  for (i = 0; i < ra; i++)
  {
    for (j = 0; j < ca; j++)
    {
      if (da[i][j] != db[i][j])
      {
        return false;
      }
    }
  }

  return true;
}

void mx_div(matrix_t *mx, const scalar_t a)
{
  const size_t     rows = mx->rows;
  const size_t     cols = mx->cols;
        scalar_t **data = mx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  uint64_t i;
  uint64_t j;

  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j += 2)
    {
      va = _mm_load_pd((data[i] + j));
      vb = _mm_set_pd(a, a);

      vc = _mm_div_pd(va, vb);

      data[i][j]   = vc[0];
      data[i][j+1] = vc[1];
    }
  }
}

void mx_mul(matrix_t *mx, const scalar_t a)
{
  const size_t     rows = mx->rows;
  const size_t     cols = mx->cols;
        scalar_t **data = mx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  uint64_t i;
  uint64_t j;

  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j += 2)
    {
      va = _mm_load_pd((data[i] + j));
      vb = _mm_set_pd(a, a);

      vc = _mm_mul_pd(va, vb);

      data[i][j]   = vc[0];
      data[i][j+1] = vc[1];
    }
  }
}

void mx_sub(matrix_t *mx, const scalar_t a)
{
  const size_t     rows = mx->rows;
  const size_t     cols = mx->cols;
        scalar_t **data = mx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  uint64_t i;
  uint64_t j;

  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j += 2)
    {
      va = _mm_load_pd((data[i] + j));
      vb = _mm_set_pd(a, a);

      vc = _mm_sub_pd(va, vb);

      data[i][j]   = vc[0];
      data[i][j+1] = vc[1];
    }
  }
}

void mx_print(const matrix_t *mx)
{
  const size_t     rows = mx->rows;
  const size_t     cols = mx->cols;
  const scalar_t **data = (const double **)mx->data;

  uint64_t i;
  uint64_t j;

  printf("[");

  for (i = 0; i < rows; i++)
  {
    if (i == 0)
    {
      printf("[%.15f, ", data[i][0]);
    }
    else
    {
      printf(" [%.15f, ", data[i][0]);
    }

    for (j = 1; j < (cols - 1); j++)
    {
      printf("%.15f, ", data[i][j]);
    }

    if ((i+1) == rows)
    {
      printf("%.15f]", data[i][j]);
    }
    else
    {
      printf("%.15f],\n", data[i][j]);
    }
  }

  printf("]\n");
}
