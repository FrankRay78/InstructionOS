#include "display/console_tests.h"
#include "display/console_HelloWorld_tests.h"
#include "display/console_scroll_tests.h"
#include "display/console_cursor_tests.h"
#include "display/framebuffer_tests.h"
#include "munit.h"


static MunitSuite kernel_suites[] = {
    { "/display", framebuffer_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE },
    { "/display", console_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE },
    { "/display", console_HelloWorld_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE },
    { "/display", console_scroll_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE },
    { "/display", console_cursor_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE },
    { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
};

static MunitSuite test_suite = { 
    "", NULL, kernel_suites, 1, MUNIT_SUITE_OPTION_NONE
};


int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&test_suite, NULL, argc, argv);
}