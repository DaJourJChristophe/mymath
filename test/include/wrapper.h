#ifndef WRAPPER_H
#define WRAPPER_H

#include "scalar.h"
#include "vector.h"

#include <stddef.h>

/**
 * @brief The maximum number of individual scalar values that are
 *        tested.
 */
#define MAX_ITEMS_TEST 20000

/**
 * @brief The starting value of x in the negative direction.
 */
#define MIN_TEST_DEPTH (scalar_t)-10.0

/**
 * @brief The final value of x in the negative direction.
 */
#define MAX_TEST_DEPTH (scalar_t)10.0

/**
 * @brief The level of precision.
 */
#define EPSILON (scalar_t)0.001

/**
 * @brief A buffer of 64-bit floating-point values to be manipulated by
 *        that target function.
 */
extern scalar_t actuals[MAX_ITEMS_TEST];

/**
 * @brief A buffer of 64-bit floating-point values to be manipulated by
 *        the alternate test function.
 */
extern scalar_t expects[MAX_ITEMS_TEST];

/**
 * @brief A namespace for the scalar operation function pointer.
 */
typedef double (*scalar_test_function_t)(const double);

/**
 * @brief A scalar test wrapper around CMocka.
 * @param function A callback function to the target function.
 */
void scalar_test(scalar_test_function_t function);

/**
 * @brief A namespace for the vector operation function pointer.
 */
typedef void (*vector_test_function_t)(double *, const size_t);

/**
 * @brief A vector test wrapper around CMocka.
 * @param function A callback function to the target function.
 */
void vector_test(vector_test_function_t function);

/**
 * @brief A namespace for the vector operation function pointer.
 */
typedef void (*vec_test_function_t)(vector_t *);

/**
 * @brief A vector test wrapper around CMocka.
 * @param function A callback function to the target function.
 */
void vec_test(vec_test_function_t function);

/**
 * @brief A namespace for the test function pointer.
 */
typedef double (*manual_test_function_t)(const double);

/**
 * @brief An initialization function setting the actuals values
 *        buffer and the expected values buffer.
 */
void init_test_cache(manual_test_function_t function);

#endif/*WRAPPER_H*/
