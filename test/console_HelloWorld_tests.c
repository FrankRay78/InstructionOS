#include "console_HelloWorld_tests.h"

MunitResult console_should_write_HelloWorld_test(const MunitParameter params[], void* user_data_or_fixture)
{
    return MUNIT_OK;
}

MunitTest console_HelloWorld_tests[] = 
{
    { "/console_should_write_HelloWorld_test", console_should_write_HelloWorld_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* Mark the end of the array with an empty entry */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};