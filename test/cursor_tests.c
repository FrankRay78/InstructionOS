#include "console_AB_tests.h"
#include "../src/console.h"
#include "cursor_mock.h"

MunitResult cursor_should_advance_on_the_same_line_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[80 * 25 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(80, 25, framebuffer, 0x00, cursor);

    // When
    console_printstring("AB");

    // Then
    munit_assert_int(2, ==, cursor_mock_x);
    munit_assert_int(0, ==, cursor_mock_y);

    return MUNIT_OK;
}

MunitResult cursor_should_advance_to_the_next_line_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[80 * 25 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(80, 25, framebuffer, 0x00, cursor);

    // When
    console_printstring("AB\n");

    // Then
    munit_assert_int(0, ==, cursor_mock_x);
    munit_assert_int(1, ==, cursor_mock_y);

    return MUNIT_OK;
}

MunitResult cursor_should_advance_to_the_next_line_and_advance_more_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[80 * 25 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(80, 25, framebuffer, 0x00, cursor);

    // When
    console_printstring("AB\nAB");

    // Then
    munit_assert_int(2, ==, cursor_mock_x);
    munit_assert_int(1, ==, cursor_mock_y);

    return MUNIT_OK;
}

MunitTest cursor_tests[] = 
{
    { "/cursor_should_advance_on_the_same_line_test", cursor_should_advance_on_the_same_line_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cursor_should_advance_to_the_next_line_test", cursor_should_advance_to_the_next_line_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/cursor_should_advance_to_the_next_line_and_advance_more_test", cursor_should_advance_to_the_next_line_and_advance_more_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* Mark the end of the array with an empty entry */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};