#ifndef PROGRAM_H
#define PROGRAM_H

#ifdef __cplusplus
extern "C"{
#endif

#include "vector.h"

#include <stddef.h>

#define INF     ((double)1.0 / (double)0.0)
#define NAN     ((double)0.0 / (double)0.0)

#define E       (double)2.718281828459045
#define PI      (double)3.141592653589793
#define PI2     (double)6.283185307179586
#define PHI     (double)1.618033988749895
#define LN2     (double)0.693147180559945
#define LN10    (double)2.302585092994046
#define LOG2E   (double)1.442695040888964
#define LOGE10  (double)0.434294481903252

/**
 * @brief Raise the Euler constant to a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __exp__(const double x);

/**
 * @brief Take the natural log of a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double ln(const double x);

/**
 * @brief Take the log base ten of a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __log10__(const double x);

/**
 * @brief Take the log base of a floating-point value and a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double logbase(const double x, const double b);

/**
 * @brief Take the log base two of a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __log2__(const double x);

/**
 * @brief Take the log of a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __log__(const double x);

/**
 * @brief Take the nth root of a floating-point value and a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double root(const double x, const double n);

/**
 * @brief Take the square root of a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __sqrt__(const double x);

/**
 * @brief Take the cubed root of a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __cbrt__(const double x);

/**
 * @brief Take the square a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __sqr__(const double x);

/**
 * @brief Take the cube a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double cub(const double x);

/**
 * @brief Take the absolute value of a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __fabs__(const double x);

/**
 * @brief Compute the absolute value of a vector.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_fabs(double *x, const size_t n);

/**
 * @brief Raise a floating-point value to a floating-point value.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __pow__(const double x, const double n);

/**
 * @brief Compute the arithmetic mean.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t AM(const vector_t *vx);

/**
 * @brief Compute the geometric mean.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t GM(const vector_t *vx);

/**
 * @brief Compute the harmonic mean.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array,
 * @return A 64 bit floating-point value.
 */
double HM(const double *x, const size_t n);

/**
 * @brief Compute the average of a vector of 64 bit
 *        floating-point scalar values.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t avg(const vector_t *vx);

/**
 * @brief Compute the hyperbolic cosine function.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __cosh__(const double x);

/**
 * @brief Compute the rectified linear unit function.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double relu(const double x);

/**
 * @brief Compute the sigmoid function.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double sigmoid(const double x);

/**
 * @brief Compute the hyperbolic sine function.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __sinh__(const double x);

/**
 * @brief Compute the hyperbolic tangent function.
 * @param x A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double __tanh__(const double x);

/**
 * @brief Calculate the population variance.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t population_variance(const vector_t *vx);

/**
 * @brief Calculate the sample variance.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t sample_variance(const vector_t *vx);

/**
 * @brief Calculate the standard deviation function.
 * @param variance A 64 bit floating-point value.
 * @return A 64 bit floating-point value.
 */
double stddev(const double variance);

/**
 * @brief Calculate the standard error of the mean.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t SEM(const vector_t *vx);

/**
 * @brief Compute the range function.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array,
 * @return A 64 bit floating-point value.
 */
double rng(const double *x, const size_t n);

/**
 * @brief Find the largest value in an array of 64 bit floating-point values.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array,
 * @return A 64 bit floating-point value.
 */
double max(const double *x, const size_t n);

/**
 * @brief Find the smallest value in an array of 64 bit floating-point values.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array,
 * @return A 64 bit floating-point value.
 */
double min(const double *x, const size_t n);

/**
 * @brief Compute the entropy function.
 * @param x An array of 64 bit floating-point values.
 * @param n The size of the array,
 * @return A 64 bit floating-point value.
 */
double entropy(const double *x, const size_t n);

/**
 * @brief Compute the mean of a vector of 64 bit floating-point scalar values.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A 64 bit floating-point scalar value.
 */
scalar_t median(const vector_t *vx);

/**
 * @brief Compute the skew of a vetor of 64 bit floating-point scalar values.
 * @param x A vector of 64 bit floating-point scalar values.
 * @return A integer value. If value is 0 than the array is uniformly
 *         distributed. If the value is 1 than the array has a right
 *         skew and if the value is -1 than the array has a left skew.
 */
int skew(const vector_t *vx);

double __floor__(const double x);

/**
 * @brief Compute the sum of an vector and a scalar.
 * @param x An array of 64 bit floating-point values.
 * @param a A 64 bit floating-point value.
 * @param n The size of the array.
 */
void vec_floor(double *x, const size_t n);

#ifdef __cplusplus
}
#endif

#endif/*PROGRAM_H*/
