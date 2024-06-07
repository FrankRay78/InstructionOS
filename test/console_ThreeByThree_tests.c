#include "console_ThreeByThree_tests.h"

MunitResult console_should_write_ABC_DEF_GHI_test(const MunitParameter params[], void* user_data_or_fixture)
{
    return MUNIT_FAIL;
}

MunitResult console_should_clear_ABC_DEF_GHI_test(const MunitParameter params[], void* user_data_or_fixture)
{
    return MUNIT_FAIL;
}

MunitResult console_should_scroll_one_line_test(const MunitParameter params[], void* user_data_or_fixture)
{
    return MUNIT_FAIL;
}

MunitResult console_should_scroll_two_lines_test(const MunitParameter params[], void* user_data_or_fixture)
{
    return MUNIT_FAIL;
}

MunitResult console_should_scroll_three_lines_test(const MunitParameter params[], void* user_data_or_fixture)
{
    return MUNIT_FAIL;
}

MunitResult console_should_scroll_and_blank_last_line(const MunitParameter params[], void* user_data_or_fixture)
{
    return MUNIT_FAIL;
}

MunitTest console_ThreeByThree_tests[] = 
{
    { "/console_should_write_ABC_DEF_GHI_test", console_should_write_ABC_DEF_GHI_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_clear_ABC_DEF_GHI_test", console_should_clear_ABC_DEF_GHI_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_scroll_one_line_test", console_should_scroll_one_line_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_scroll_two_lines_test", console_should_scroll_two_lines_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_scroll_three_lines_test", console_should_scroll_three_lines_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_scroll_and_blank_last_line", console_should_scroll_and_blank_last_line, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* Mark the end of the array with an empty entry */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};