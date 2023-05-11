#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <cmocka.h>
#include "wrapper.h"

#include "common.h"
#include "program.h"
#include "scalar.h"

/**
 * @brief An alternant implementation of the floating-point absolute
 *        value function for testing purposes.
 * @param x A 64 bit floating-point scalar value.
 */
static scalar_t __manual_cub__(scalar_t x)
{
  return x * x * x;
}

/**
 * @brief A test for the scalar operation of a 64 bit floating-point
 *        absolute value function.
 * @param state A multidimensional list of objects used by CMocka.
 */
static void scalar_cub_test(void unused **state)
{
  scalar_test(&cub);
}

/**
 * @brief A test for the vector operation of a 64 bit floating-point
 *        absolute value function.
 * @param state A multidimensional list of objects used by CMocka.
 */
static void vector_cub_test(void unused **state)
{
}

/**
 * @brief The test start.
 * @return An integer return status.
 */
int main(void)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(scalar_cub_test),
    cmocka_unit_test(vector_cub_test),
  };

  init_test_cache(&__manual_cub__);

  return cmocka_run_group_tests(tests, NULL, NULL);
}
