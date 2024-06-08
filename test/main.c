#include "main.h"


static MunitSuite kernel_suites[] = {
  { "", framebuffer_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE },
  { "", console_AB_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE },
  { "", console_HelloWorld_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE },
  { "", console_ThreeByThree_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE },
  { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
};

static MunitSuite test_suite = { 
  "/kernel", NULL, kernel_suites, 1, MUNIT_SUITE_OPTION_NONE
};


int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
	return munit_suite_main(&test_suite, NULL, argc, argv);
}