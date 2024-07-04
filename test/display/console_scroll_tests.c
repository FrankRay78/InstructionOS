#include "console_scroll_tests.h"
#include "../../src/display/console.h"
#include "cursor_mock.h"

MunitResult console_should_scroll_one_line_test(const MunitParameter params[], void* user_data_or_fixture)
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
    munit_assert_char('B', ==, framebuffer[0]);
    munit_assert_char('B', ==, framebuffer[2]);
    munit_assert_char('B', ==, framebuffer[4]);
    munit_assert_char('C', ==, framebuffer[6]);
    munit_assert_char('C', ==, framebuffer[8]);
    munit_assert_char('C', ==, framebuffer[10]);
    munit_assert_char(' ', ==, framebuffer[12]);
    munit_assert_char(' ', ==, framebuffer[14]);
    munit_assert_char(' ', ==, framebuffer[16]);

    return MUNIT_OK;
}

MunitResult console_should_scroll_two_lines_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[3 * 3 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(3, 3, framebuffer, 0x00, cursor);

    // When
    console_printstring("AAA");
    console_printstring("BBB");
    console_printstring("CCC");
    console_printstring("DDD");

    // Then
    munit_assert_char('C', ==, framebuffer[0]);
    munit_assert_char('C', ==, framebuffer[2]);
    munit_assert_char('C', ==, framebuffer[4]);
    munit_assert_char('D', ==, framebuffer[6]);
    munit_assert_char('D', ==, framebuffer[8]);
    munit_assert_char('D', ==, framebuffer[10]);
    munit_assert_char(' ', ==, framebuffer[12]);
    munit_assert_char(' ', ==, framebuffer[14]);
    munit_assert_char(' ', ==, framebuffer[16]);

    return MUNIT_OK;
}


MunitResult console_should_scroll_on_newline_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[3 * 3 * 2];
    Cursor cursor = create_cursor_mock();
    console_initialise(3, 3, framebuffer, 0x00, cursor);
    console_clear(); // nb. explicitly clear the whole framebuffer given we are scrolling on a part rendered line

    // When
    console_printstring("AAA");
    console_printstring("BBB");
    console_printstring("\n");

    // Then
    munit_assert_char('B', ==, framebuffer[0]);
    munit_assert_char('B', ==, framebuffer[2]);
    munit_assert_char('B', ==, framebuffer[4]);
    munit_assert_char(' ', ==, framebuffer[6]);
    munit_assert_char(' ', ==, framebuffer[8]);
    munit_assert_char(' ', ==, framebuffer[10]);
    munit_assert_char(' ', ==, framebuffer[12]);
    munit_assert_char(' ', ==, framebuffer[14]);
    munit_assert_char(' ', ==, framebuffer[16]);

    return MUNIT_OK;
}

MunitTest console_scroll_tests[] = 
{
    { "/console_should_scroll_one_line_test", console_should_scroll_one_line_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_scroll_two_lines_test", console_should_scroll_two_lines_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_scroll_on_newline_test", console_should_scroll_on_newline_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* Mark the end of the array with an empty entry */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};