#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include <cmocka.h>
#include "wrapper.h"

#include "common.h"
#include "program.h"
#include "scalar.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief An alternant implementation of the floating-point floor
 *        function for testing purposes.
 * @param x A 64 bit floating-point scalar value.
 */
static scalar_t __manual_sinh__(scalar_t x)
{
  return sinh(x);
}

/**
 * @brief A test for the scalar operation of a 64 bit floating-point
 *        cubed root function.
 * @param state A multidimensional list of objects used by CMocka.
 */
static void scalar_sinh_test(void unused **state)
{
  scalar_test(&__sinh__);
}

/**
 * @brief A test for the vector operation of a 64 bit floating-point
 *        cubed root function.
 * @param state A multidimensional list of objects used by CMocka.
 */
// static void vector_sinh_test(void unused **state)
// {
// }

/**
 * @brief The test start.
 * @return An integer return status.
 */
int main(void)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(scalar_sinh_test),
    //cmocka_unit_test(vector_sinh_test),
  };

  init_test_cache(&__manual_sinh__);

  return cmocka_run_group_tests(tests, NULL, NULL);
}
