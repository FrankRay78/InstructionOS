#include "console_cursor_tests.h"
#include "../src/display/console.h"
#include "cursor_mock.h"

MunitResult console_cursor_should_initialise_to_zero_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[80 * 25 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(80, 25, framebuffer, 0x00, cursor);

    // When
    console_printstring("AB");
    cursor = create_cursor_mock();

    // Then
    munit_assert_int(0, ==, cursor_mock_x);
    munit_assert_int(0, ==, cursor_mock_y);

    return MUNIT_OK;
}

MunitResult console_cursor_should_advance_on_the_same_line_test(const MunitParameter params[], void* user_data_or_fixture)
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

MunitResult console_cursor_should_advance_to_the_next_line_test(const MunitParameter params[], void* user_data_or_fixture)
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

MunitResult console_cursor_should_advance_to_the_next_line_and_advance_test(const MunitParameter params[], void* user_data_or_fixture)
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

MunitResult console_cursor_should_stay_on_the_last_line_after_scrolling_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[3 * 3 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(3, 3, framebuffer, 0x00, cursor);

    // When
    console_printstring("AAA");
    console_printstring("BBB");
    console_printstring("CCC");

    // Then
    munit_assert_int(0, ==, cursor_mock_x);
    munit_assert_int(2, ==, cursor_mock_y);

    return MUNIT_OK;
}

MunitResult console_cursor_should_stay_on_the_last_line_after_scrolling_and_advance_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[3 * 3 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(3, 3, framebuffer, 0x00, cursor);

    // When
    console_printstring("AAA");
    console_printstring("BBB");
    console_printstring("CCC");
    console_printstring("D");

    // Then
    munit_assert_int(1, ==, cursor_mock_x);
    munit_assert_int(2, ==, cursor_mock_y);

    return MUNIT_OK;
}

MunitTest console_cursor_tests[] = 
{
    { "/console_cursor_should_initialise_to_zero_test", console_cursor_should_initialise_to_zero_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_cursor_should_advance_on_the_same_line_test", console_cursor_should_advance_on_the_same_line_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_cursor_should_advance_to_the_next_line_test", console_cursor_should_advance_to_the_next_line_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_cursor_should_advance_to_the_next_line_and_advance_test", console_cursor_should_advance_to_the_next_line_and_advance_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_cursor_should_stay_on_the_last_line_after_scrolling_test", console_cursor_should_stay_on_the_last_line_after_scrolling_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_cursor_should_stay_on_the_last_line_after_scrolling_and_advance_test", console_cursor_should_stay_on_the_last_line_after_scrolling_and_advance_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* Mark the end of the array with an empty entry */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};