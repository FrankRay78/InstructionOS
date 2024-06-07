#include "console_AB_tests.h"

MunitResult console_should_write_AB_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(80 * 25 * 2);
    console_initialise(80, 25, 2, framebuffer, 0x00);

    // When
    console_printstring("AB");

    // Then
    munit_assert_char('A', ==, framebuffer[0]);
    munit_assert_char('B', ==, framebuffer[2]);

    return MUNIT_OK;
}

MunitResult console_should_clear_AB_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(80 * 25 * 2);
    console_initialise(80, 25, 2, framebuffer, 0x00);

    // When
    console_printstring("AB");
    console_clear();

    // Then
    munit_assert_char(' ', ==, framebuffer[0]);
    munit_assert_char(' ', ==, framebuffer[2]);

    return MUNIT_OK;
}

MunitResult console_should_write_A_EOL_B_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(80 * 25 * 2);
    console_initialise(80, 25, 2, framebuffer, 0x00);

    // When
    console_printstring("A\nB");

    // Then
    munit_assert_char('A', ==, framebuffer[0]);
    munit_assert_char('B', ==, framebuffer[80 * 2 + 0]);

    return MUNIT_OK;
}

MunitResult console_should_clear_A_EOL_B_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(80 * 25 * 2);
    console_initialise(80, 25, 2, framebuffer, 0x00);

    // When
    console_printstring("A\nB");
    console_clear();

    // Then
    munit_assert_char(' ', ==, framebuffer[0]);
    munit_assert_char(' ', ==, framebuffer[80 * 2 + 0]);

    return MUNIT_OK;
}

MunitTest console_AB_tests[] = 
{
    { "/console_should_write_AB_test", console_should_write_AB_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_clear_AB_test", console_should_clear_AB_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_write_A_EOL_B_test", console_should_write_A_EOL_B_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_clear_A_EOL_B_test", console_should_clear_A_EOL_B_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* Mark the end of the array with an empty entry */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};