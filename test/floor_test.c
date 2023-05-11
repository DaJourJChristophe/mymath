#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <cmocka.h>
#include "wrapper.h"

#include "common.h"
#include "program.h"
#include "scalar.h"

#include <stdint.h>
#include <stdio.h>

/**
 * @brief An alternant implementation of the floating-point floor
 *        function for testing purposes.
 * @param x A 64 bit floating-point scalar value.
 */
static scalar_t __manual_floor__(scalar_t x)
{
  return (double)((int)(x));
}

/**
 * @brief A test for the scalar operation of a 64 bit floating-point
 *        floor function.
 * @param state A multidimensional list of objects used by CMocka.
 */
static void scalar_floor_test(void unused **state)
{
  scalar_test(&__floor__);
}

/**
 * @brief A test for the vector operation of a 64 bit floating-point
 *        floor function.
 * @param state A multidimensional list of objects used by CMocka.
 */
static void vector_floor_test(void unused **state)
{
  vector_test(&vec_floor);
}

/**
 * @brief The test start.
 * @return An integer return status.
 */
int main(void)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(scalar_floor_test),
    cmocka_unit_test(vector_floor_test),
  };

  init_test_cache(&__manual_floor__);

  return cmocka_run_group_tests(tests, NULL, NULL);
}
