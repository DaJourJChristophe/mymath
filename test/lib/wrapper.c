#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <cmocka.h>
#include "wrapper.h"

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "scalar.h"

/**
 * @brief A buffer of 64-bit floating-point values to be manipulated by
 *        that target function.
 */
scalar_t actuals[MAX_ITEMS_TEST];

/**
 * @brief A buffer of 64-bit floating-point values to be manipulated by
 *        the alternate test function.
 */
scalar_t expects[MAX_ITEMS_TEST];

/**
 * @brief A scalar test wrapper around CMocka.
 * @param function A callback function to the target function.
 */
void scalar_test(scalar_test_function_t function)
{
  const scalar_t epsilon = EPSILON;

  for (uint64_t i = 0; i < MAX_ITEMS_TEST; i++)
  {
    assert_float_equal(function(actuals[i]), expects[i], epsilon);
  }
}

/**
 * @brief A vector test wrapper around CMocka.
 * @param function A callback function to the target function.
 */
void vector_test(vector_test_function_t function)
{
  const scalar_t epsilon = EPSILON;

  function(actuals, MAX_ITEMS_TEST);

  for (uint64_t i = 0; i < MAX_ITEMS_TEST; i++)
  {
    assert_float_equal(actuals[i], expects[i], epsilon);
  }
}

/**
 * @brief A vector test wrapper around CMocka.
 * @param function A callback function to the target function.
 */
void vec_test(vec_test_function_t function)
{
  const scalar_t epsilon = EPSILON;

  vector_t vx;
  memset(&vx, 0, sizeof(vector_t));
  vx.data = actuals;
  vx.size = MAX_ITEMS_TEST;

  function(&vx);

  assert_int_equal(vx.size, MAX_ITEMS_TEST);
  assert_ptr_equal(vx.data, actuals);

  for (uint64_t i = 0; i < MAX_ITEMS_TEST; i++)
  {
    assert_float_equal(actuals[i], expects[i], epsilon);
  }
}

/**
 * @brief An initialization function setting the actuals values
 *        buffer and the expected values buffer.
 */
void init_test_cache(manual_test_function_t function)
{
  const scalar_t epsilon = EPSILON;
  const scalar_t n       = MAX_TEST_DEPTH;
        scalar_t x       = MIN_TEST_DEPTH;

  memset(actuals, 0, (MAX_ITEMS_TEST * sizeof(scalar_t)));
  memset(expects, 0, (MAX_ITEMS_TEST * sizeof(scalar_t)));

  for (uint64_t i = 0; i < MAX_ITEMS_TEST && x < n; x += epsilon, i++)
  {
    actuals[i] = x;
    expects[i] = function(x);
  }
}
