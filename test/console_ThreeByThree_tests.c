#include "console_ThreeByThree_tests.h"

MunitResult console_should_write_ABC_DEF_GHI_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(3 * 3 * 2);
    console_initialise(3, 3, 2, framebuffer, 0x00);

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
    unsigned char* framebuffer = (unsigned char*)malloc(3 * 3 * 2);
    console_initialise(3, 3, 2, framebuffer, 0x00);

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

MunitResult console_should_scroll_one_line_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(3 * 3 * 2);
    console_initialise(3, 3, 2, framebuffer, 0x00);

    // When
    console_printstring("AAA");
    console_printstring("BBB");
    console_printstring("CCC");
    console_printstring("DDD");

    // Then
    munit_assert_char('B', ==, framebuffer[0]);
    munit_assert_char('B', ==, framebuffer[2]);
    munit_assert_char('B', ==, framebuffer[4]);
    munit_assert_char('C', ==, framebuffer[6]);
    munit_assert_char('C', ==, framebuffer[8]);
    munit_assert_char('C', ==, framebuffer[10]);
    munit_assert_char('D', ==, framebuffer[12]);
    munit_assert_char('D', ==, framebuffer[14]);
    munit_assert_char('D', ==, framebuffer[16]);

    return MUNIT_OK;
}

MunitResult console_should_scroll_two_lines_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(3 * 3 * 2);
    console_initialise(3, 3, 2, framebuffer, 0x00);

    // When
    console_printstring("AAA");
    console_printstring("BBB");
    console_printstring("CCC");
    console_printstring("DDD");
    console_printstring("EEE");

    // Then
    munit_assert_char('C', ==, framebuffer[0]);
    munit_assert_char('C', ==, framebuffer[2]);
    munit_assert_char('C', ==, framebuffer[4]);
    munit_assert_char('D', ==, framebuffer[6]);
    munit_assert_char('D', ==, framebuffer[8]);
    munit_assert_char('D', ==, framebuffer[10]);
    munit_assert_char('E', ==, framebuffer[12]);
    munit_assert_char('E', ==, framebuffer[14]);
    munit_assert_char('E', ==, framebuffer[16]);

    return MUNIT_OK;
}

MunitResult console_should_scroll_three_lines_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(3 * 3 * 2);
    console_initialise(3, 3, 2, framebuffer, 0x00);

    // When
    console_printstring("AAA");
    console_printstring("BBB");
    console_printstring("CCC");
    console_printstring("DDD");
    console_printstring("EEE");
    console_printstring("FFF");

    // Then
    munit_assert_char('D', ==, framebuffer[0]);
    munit_assert_char('D', ==, framebuffer[2]);
    munit_assert_char('D', ==, framebuffer[4]);
    munit_assert_char('E', ==, framebuffer[6]);
    munit_assert_char('E', ==, framebuffer[8]);
    munit_assert_char('E', ==, framebuffer[10]);
    munit_assert_char('F', ==, framebuffer[12]);
    munit_assert_char('F', ==, framebuffer[14]);
    munit_assert_char('F', ==, framebuffer[16]);

    return MUNIT_OK;
}

MunitResult console_should_scroll_and_blank_last_line_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(3 * 3 * 2);
    console_initialise(3, 3, 2, framebuffer, 0x00);

    // When
    console_printstring("AAA");
    console_printstring("BBB");
    console_printstring("CCC");
    console_printstring("D");

    // Then
    munit_assert_char('B', ==, framebuffer[0]);
    munit_assert_char('B', ==, framebuffer[2]);
    munit_assert_char('B', ==, framebuffer[4]);
    munit_assert_char('C', ==, framebuffer[6]);
    munit_assert_char('C', ==, framebuffer[8]);
    munit_assert_char('C', ==, framebuffer[10]);
    munit_assert_char('D', ==, framebuffer[12]);
    munit_assert_char(' ', ==, framebuffer[14]);
    munit_assert_char(' ', ==, framebuffer[16]);

    return MUNIT_OK;
}

MunitTest console_ThreeByThree_tests[] = 
{
    { "/console_should_write_ABC_DEF_GHI_test", console_should_write_ABC_DEF_GHI_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_clear_ABC_DEF_GHI_test", console_should_clear_ABC_DEF_GHI_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_scroll_one_line_test", console_should_scroll_one_line_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_scroll_two_lines_test", console_should_scroll_two_lines_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_scroll_three_lines_test", console_should_scroll_three_lines_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_scroll_and_blank_last_line_test", console_should_scroll_and_blank_last_line_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* Mark the end of the array with an empty entry */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};