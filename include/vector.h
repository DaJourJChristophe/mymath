#ifndef VECTOR_H
#define VECTOR_H

#ifdef __cplusplus
extern "C"{
#endif

#include "scalar.h"

#include <stddef.h>

struct vector
{
  scalar_t *data __attribute__ ((aligned(16)));
  size_t    size;
};

/**
 * @brief A namespace for the vector data structure.
 */
typedef struct vector vector_t;

/**
 * @brief Compute the sum of a vector.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t vc_sum(const vector_t *vx);

/**
 * @brief Compute the product of a vector.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t vc_product(const vector_t *vx);

/**
 * @brief Compute the sum of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vecadd(vector_t *vx, const scalar_t a);

/**
 * @brief Compute the sum of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void vecaddvec(vector_t *vx, const vector_t *vm);

/**
 * @brief Compute the sum of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecadd(double *y, const vector_t *vx, const scalar_t a);

/**
 * @brief Compute the sum of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecaddvec(double *y, const vector_t *vx, const vector_t *vm);

/**
 * @brief Compute the quotient of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vecdiv(vector_t *vx, const scalar_t a);

/**
 * @brief Compute the quotient of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void vecdivvec(vector_t *vx, const vector_t *vm);

/**
 * @brief Compute the quotient of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecdiv(double *y, const vector_t *vx, const scalar_t a);

/**
 * @brief Compute the quotient of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecdivvec(double *y, const vector_t *vx, const vector_t *a);

/**
 * @brief Compute the exponential of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void vecexp(vector_t *vx);

/**
 * @brief Compute the exponential of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecexp(double *y, const vector_t *vx);

/**
 * @brief Compute the product of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vecmul(vector_t *vx, const scalar_t a);

/**
 * @brief Compute the product of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void vecmulvec(vector_t *vx, const vector_t *vm);

/**
 * @brief Compute the product of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecmul(double *y, const vector_t *vx, const scalar_t a);

/**
 * @brief Compute the product of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecmulvec(double *y, const vector_t *vx, const vector_t *vm);

/**
 * @brief Compute the difference of a vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vecsub(vector_t *vx, const scalar_t a);

/**
 * @brief Compute the difference of a vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void vecsubvec(vector_t *vx, const vector_t *vm);

/**
 * @brief Compute the difference of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecsub(double *y, const vector_t *vx, const scalar_t a);

/**
 * @brief Compute the difference of an vector and a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a An array of 64 bit floating-point values.
 * @param n The size of the array.
 * @return An array of 64 bit floating-point values.
 */
void immvecsubvec(double *y, const vector_t *vx, const vector_t *vm);

/**
 * @brief Print a vector to the stdout.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array.
 */
void vector_print(const vector_t *vx);

#ifdef __cplusplus
}
#endif

#endif/*VECTOR_H*/
