#include "munit.h"

MunitResult my_test(const MunitParameter params[], void* user_data_or_fixture) {
	munit_assert(0 != 1);
}

MunitTest console_tests[] = {
  { "/my-test", my_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  /* Mark the end of the array with an empty entry */
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};