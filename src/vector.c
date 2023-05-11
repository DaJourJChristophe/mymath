#include "program.h"
#include "scalar.h"
#include "vector.h"

#include <immintrin.h>

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief Compute the sum of a vector.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t vc_sum(const vector_t *vx)
{
  const size_t    n = vx->size;
        scalar_t *x = vx->data;

  double sum = 0.0;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 4)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_load_pd((x + i + 2));

    vc = _mm_add_pd(va, vb);

    sum += vc[0] + vc[1];
  }

  return sum;
}

/**
 * @brief Compute the product of a vector.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t vc_product(const vector_t *vx)
{
  const size_t    n = vx->size;
        scalar_t *x = vx->data;

  double product = 1.0;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 4)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_load_pd((x + i + 2));

    vc = _mm_mul_pd(va, vb);

    product *= vc[0] * vc[1];
  }

  return product;
}

/**
 * @brief Compute the sum of a vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vecadd(vector_t *vx, const scalar_t a)
{
  const size_t    n = vx->size;
        scalar_t *x = vx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_set_pd(a, a);

    vc = _mm_add_pd(va, vb);

    x[i]   = vc[0];
    x[i+1] = vc[1];
  }
}

/**
 * @brief Compute the sum of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void vecaddvec(vector_t *vx, const vector_t *vm)
{
  const size_t    n = vx->size;
        scalar_t *x = vx->data;
        scalar_t *m = vm->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_load_pd((m + i));

    vc = _mm_add_pd(va, vb);

    x[i]   = vc[0];
    x[i+1] = vc[1];
  }
}

/**
 * @brief Compute the sum of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecadd(double *y, const vector_t *vx, const scalar_t a)
{
  const size_t    n = vx->size;
  const scalar_t *x = vx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_set_pd(a, a);

    vc = _mm_add_pd(va, vb);

    y[i]   = vc[0];
    y[i+1] = vc[1];
  }
}

/**
 * @brief Compute the sum of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecaddvec(double *y, const vector_t *vx, const vector_t *vm)
{
  const size_t    n = vx->size;
  const scalar_t *x = vx->data;
        scalar_t *m = vm->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_load_pd((m + i));

    vc = _mm_add_pd(va, vb);

    y[i]   = vc[0];
    y[i+1] = vc[1];
  }
}

/**
 * @brief Compute the cross product of a vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void veccxpvec(double *y, const vector_t *vx, const vector_t *vm)
{
  const scalar_t *x = vx->data;
  const scalar_t *m = vm->data;

  y[0] = x[1] * m[2] - x[2] * m[1];
  y[1] = x[2] * m[0] - x[0] * m[2];
  y[2] = x[0] * m[1] - x[1] * m[0];
}

/**
 * @brief Compute the quotient of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vecdiv(vector_t *vx, const scalar_t a)
{
  const size_t    n = vx->size;
        scalar_t *x = vx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_set_pd(a, a);

    vc = _mm_div_pd(va, vb);

    x[i]   = vc[0];
    x[i+1] = vc[1];
  }
}

/**
 * @brief Compute the quotient of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void vecdivvec(vector_t *vx, const vector_t *vm)
{
  const size_t    n = vx->size;
        scalar_t *x = vx->data;
        scalar_t *m = vm->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_load_pd((m + i));

    vc = _mm_div_pd(va, vb);

    x[i]   = vc[0];
    x[i+1] = vc[1];
  }
}

/**
 * @brief Compute the quotient of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecdiv(double *y, const vector_t *vx, const scalar_t a)
{
  const size_t    n = vx->size;
  const scalar_t *x = vx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_set_pd(a, a);

    vc = _mm_div_pd(va, vb);

    y[i]   = vc[0];
    y[i+1] = vc[1];
  }
}

/**
 * @brief Compute the quotient of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecdivvec(double *y, const vector_t *vx, const vector_t *vm)
{
  const size_t    n = vx->size;
  const scalar_t *x = vx->data;
  const scalar_t *m = vm->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_load_pd((m + i));

    vc = _mm_div_pd(va, vb);

    y[i]   = vc[0];
    y[i+1] = vc[1];
  }
}

/**
 * @brief Compute the dot product of a vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 * @return A 64 bit floating-point value.
 */
double vecdotvec(const vector_t *vx, const vector_t *vm)
{
  const size_t    n = vx->size;
  const scalar_t *m = vm->data;
        scalar_t *x = vx->data;

  double sum = 0.0;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_load_pd((m + i));

    vc = _mm_mul_pd(va, vb);

    sum += vc[0];
    sum += vc[1];
  }

  return sum;
}

/**
 * @brief Compute the exponential of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void vecexp(vector_t *vx)
{
  const size_t    n = vx->size;
        scalar_t *x = vx->data;

  for (uint64_t i = 0; i < n; i++)
  {
    x[i] = __exp__(x[i]);
  }
}

/**
 * @brief Compute the exponential of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecexp(double *y, const vector_t *vx)
{
  const size_t    n = vx->size;
        scalar_t *x = vx->data;

  for (uint64_t i = 0; i < n; i++)
  {
    y[i] = __exp__(x[i]);
  }
}

/**
 * @brief Compute the product of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vecmul(vector_t *vx, const scalar_t a)
{
  const size_t    n = vx->size;
        scalar_t *x = vx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_set_pd(a, a);

    vc = _mm_mul_pd(va, vb);

    x[i]   = vc[0];
    x[i+1] = vc[1];
  }
}

/**
 * @brief Compute the product of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void vecmulvec(vector_t *vx, const vector_t *vm)
{
  const size_t    n = vx->size;
  const scalar_t *m = vm->data;
        scalar_t *x = vx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_load_pd((m + i));

    vc = _mm_mul_pd(va, vb);

    x[i]   = vc[0];
    x[i+1] = vc[1];
  }
}

/**
 * @brief Compute the product of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecmul(double *y, const vector_t *vx, const scalar_t a)
{
  const size_t    n = vx->size;
        scalar_t *x = vx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_set_pd(a, a);

    vc = _mm_mul_pd(va, vb);

    y[i]   = vc[0];
    y[i+1] = vc[1];
  }
}

/**
 * @brief Compute the product of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecmulvec(double *y, const vector_t *vx, const vector_t *vm)
{
  const size_t    n = vx->size;
  const scalar_t *m = vm->data;
        scalar_t *x = vx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_load_pd((m + i));

    vc = _mm_mul_pd(va, vb);

    y[i]   = vc[0];
    y[i+1] = vc[1];
  }
}

/**
 * @brief Compute the difference of a vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vecsub(vector_t *vx, const scalar_t a)
{
  const size_t     n = vx->size;
        scalar_t *x = vx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_set_pd(a, a);

    vc = _mm_sub_pd(va, vb);

    x[i]   = vc[0];
    x[i+1] = vc[1];
  }
}

/**
 * @brief Compute the difference of a vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void vecsubvec(vector_t *vx, const vector_t *vm)
{
  const size_t    n = vx->size;
  const scalar_t *m = vm->data;
        scalar_t *x = vx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_load_pd((m + i));

    vc = _mm_sub_pd(va, vb);

    x[i]   = vc[0];
    x[i+1] = vc[1];
  }
}

/**
 * @brief Compute the difference of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecsub(double *y, const vector_t *vx, const scalar_t a)
{
  const size_t    n = vx->size;
        scalar_t *x = vx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_set_pd(a, a);

    vc = _mm_sub_pd(va, vb);

    y[i]   = vc[0];
    y[i+1] = vc[1];
  }
}

/**
 * @brief Compute the difference of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecsubvec(double *y, const vector_t *vx, const vector_t *vm)
{
  const size_t    n = vx->size;
  const scalar_t *m = vm->data;
        scalar_t *x = vx->data;

  __m128d va;
  __m128d vb;
  __m128d vc;

  for (uint64_t i = 0; i < n; i += 2)
  {
    va = _mm_load_pd((x + i));
    vb = _mm_load_pd((m + i));

    vc = _mm_sub_pd(va, vb);

    y[i]   = vc[0];
    y[i+1] = vc[1];
  }
}

/**
 * @brief Print a vector to the stdout.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void vector_print(const vector_t *vx)
{
  const size_t    n = vx->size;
        scalar_t *x = vx->data;

  uint64_t i;

  printf("[%.15f,\n", x[0]);

  for (i = 1; i < (n - 1); i++)
  {
    printf(" %.15f,\n", x[i]);
  }

  printf(" %.15f]\n", x[i]);
}
