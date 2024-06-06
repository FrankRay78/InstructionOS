#include "main.h"

static const MunitSuite suite = {
  (char*) "console_tests", /* name */
  console_tests, /* tests */
  NULL, /* suites */
  1, /* iterations */
  MUNIT_SUITE_OPTION_NONE /* options */
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
	return munit_suite_main(&suite, NULL, argc, argv);
}