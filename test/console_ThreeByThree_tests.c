#include "console_ThreeByThree_tests.h"

MunitResult console_should_write_ABC_DEF_GHI_test(const MunitParameter params[], void* user_data_or_fixture)
{
    return MUNIT_OK;
}

MunitTest console_ThreeByThree_tests[] = 
{
    { "/console_should_write_ABC_DEF_GHI_test", console_should_write_ABC_DEF_GHI_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* Mark the end of the array with an empty entry */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};