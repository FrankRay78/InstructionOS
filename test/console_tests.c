#include "console_tests.h"
#include "../src/console.h"
#include "cursor_mock.h"


/*
 * Console AB tests
 */

MunitResult console_should_write_AB_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[80 * 25 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(80, 25, framebuffer, 0x00, cursor);

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
    unsigned char framebuffer[80 * 25 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(80, 25, framebuffer, 0x00, cursor);

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
    unsigned char framebuffer[80 * 25 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(80, 25, framebuffer, 0x00, cursor);

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
    unsigned char framebuffer[80 * 25 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(80, 25, framebuffer, 0x00, cursor);

    // When
    console_printstring("A\nB");
    console_clear();

    // Then
    munit_assert_char(' ', ==, framebuffer[0]);
    munit_assert_char(' ', ==, framebuffer[80 * 2 + 0]);

    return MUNIT_OK;
}


/*
 * Console ABCDEFGHI tests
 */

MunitResult console_should_write_ABC_DEF_GHI_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[3 * 4 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(3, 4, framebuffer, 0x00, cursor);

    // When
    console_printstring("ABCDEFGHI");

    // Then
    munit_assert_char('A', ==, framebuffer[0]);
    munit_assert_char('B', ==, framebuffer[2]);
    munit_assert_char('C', ==, framebuffer[4]);
    munit_assert_char('D', ==, framebuffer[6]);
    munit_assert_char('E', ==, framebuffer[8]);
    munit_assert_char('F', ==, framebuffer[10]);
    munit_assert_char('G', ==, framebuffer[12]);
    munit_assert_char('H', ==, framebuffer[14]);
    munit_assert_char('I', ==, framebuffer[16]);

    return MUNIT_OK;
}

MunitResult console_should_clear_ABC_DEF_GHI_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[3 * 4 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(3, 4, framebuffer, 0x00, cursor);

    // When
    console_printstring("ABCDEFGHI");
    console_clear();

    // Then
    munit_assert_char(' ', ==, framebuffer[0]);
    munit_assert_char(' ', ==, framebuffer[2]);
    munit_assert_char(' ', ==, framebuffer[4]);
    munit_assert_char(' ', ==, framebuffer[6]);
    munit_assert_char(' ', ==, framebuffer[8]);
    munit_assert_char(' ', ==, framebuffer[10]);
    munit_assert_char(' ', ==, framebuffer[12]);
    munit_assert_char(' ', ==, framebuffer[14]);
    munit_assert_char(' ', ==, framebuffer[16]);

    return MUNIT_OK;
}


MunitTest console_tests[] = 
{
    { "/console_should_write_AB_test", console_should_write_AB_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_clear_AB_test", console_should_clear_AB_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_write_A_EOL_B_test", console_should_write_A_EOL_B_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_clear_A_EOL_B_test", console_should_clear_A_EOL_B_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_write_ABC_DEF_GHI_test", console_should_write_ABC_DEF_GHI_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_clear_ABC_DEF_GHI_test", console_should_clear_ABC_DEF_GHI_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* Mark the end of the array with an empty entry */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};