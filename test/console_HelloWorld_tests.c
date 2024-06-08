#include "console_HelloWorld_tests.h"

MunitResult console_should_write_hello_world_with_printstring_statement_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(80 * 25 * 2);
    console_initialise(80, 25, 2, framebuffer, 0x00);
    
    // When
    console_printstring("Hello World");

    // Then
    munit_assert_char('H', ==, framebuffer[0]);
    munit_assert_char('e', ==, framebuffer[2]);
    munit_assert_char('l', ==, framebuffer[4]);
    munit_assert_char('l', ==, framebuffer[6]);
    munit_assert_char('o', ==, framebuffer[8]);
    munit_assert_char(' ', ==, framebuffer[10]);
    munit_assert_char('W', ==, framebuffer[12]);
    munit_assert_char('o', ==, framebuffer[14]);
    munit_assert_char('r', ==, framebuffer[16]);
    munit_assert_char('l', ==, framebuffer[18]);
    munit_assert_char('d', ==, framebuffer[20]);

    return MUNIT_OK;
}

MunitResult console_should_write_hello_world_with_printstring_statements_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(80 * 25 * 2);
    console_initialise(80, 25, 2, framebuffer, 0x00);

    // When
    console_printstring("Hello");
    console_printstring(" ");
    console_printstring("World");

    // Then
    munit_assert_char('H', ==, framebuffer[0]);
    munit_assert_char('e', ==, framebuffer[2]);
    munit_assert_char('l', ==, framebuffer[4]);
    munit_assert_char('l', ==, framebuffer[6]);
    munit_assert_char('o', ==, framebuffer[8]);
    munit_assert_char(' ', ==, framebuffer[10]);
    munit_assert_char('W', ==, framebuffer[12]);
    munit_assert_char('o', ==, framebuffer[14]);
    munit_assert_char('r', ==, framebuffer[16]);
    munit_assert_char('l', ==, framebuffer[18]);
    munit_assert_char('d', ==, framebuffer[20]);

    return MUNIT_OK;
}

MunitResult console_should_write_hello_CRLF_world_with_printstring_statement_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(80 * 25 * 2);
    console_initialise(80, 25, 2, framebuffer, 0x00);

    // When
    console_printstring("Hello\nWorld\n");

    // Then
    munit_assert_char('H', ==, framebuffer[0]);
    munit_assert_char('e', ==, framebuffer[2]);
    munit_assert_char('l', ==, framebuffer[4]);
    munit_assert_char('l', ==, framebuffer[6]);
    munit_assert_char('o', ==, framebuffer[8]);
    munit_assert_char('W', ==, framebuffer[80 * 2 + 0]);
    munit_assert_char('o', ==, framebuffer[80 * 2 + 2]);
    munit_assert_char('r', ==, framebuffer[80 * 2 + 4]);
    munit_assert_char('l', ==, framebuffer[80 * 2 + 6]);
    munit_assert_char('d', ==, framebuffer[80 * 2 + 8]);

    return MUNIT_OK;
}

MunitResult console_should_write_hello_CRLF_world_with_printstring_statements_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(80 * 25 * 2);
    console_initialise(80, 25, 2, framebuffer, 0x00);

    // When
    console_printstring("Hello\n");
    console_printstring("World\n");

    // Then
    munit_assert_char('H', ==, framebuffer[0]);
    munit_assert_char('e', ==, framebuffer[2]);
    munit_assert_char('l', ==, framebuffer[4]);
    munit_assert_char('l', ==, framebuffer[6]);
    munit_assert_char('o', ==, framebuffer[8]);
    munit_assert_char('W', ==, framebuffer[80 * 2 + 0]);
    munit_assert_char('o', ==, framebuffer[80 * 2 + 2]);
    munit_assert_char('r', ==, framebuffer[80 * 2 + 4]);
    munit_assert_char('l', ==, framebuffer[80 * 2 + 6]);
    munit_assert_char('d', ==, framebuffer[80 * 2 + 8]);

    return MUNIT_OK;
}

MunitResult console_should_write_hello_CRLF_world_with_printline_statements_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char* framebuffer = (unsigned char*)malloc(80 * 25 * 2);
    console_initialise(80, 25, 2, framebuffer, 0x00);

    // When
    console_printline("Hello");
    console_printline("World");

    // Then
    munit_assert_char('H', ==, framebuffer[0]);
    munit_assert_char('e', ==, framebuffer[2]);
    munit_assert_char('l', ==, framebuffer[4]);
    munit_assert_char('l', ==, framebuffer[6]);
    munit_assert_char('o', ==, framebuffer[8]);
    munit_assert_char('W', ==, framebuffer[80 * 2 + 0]);
    munit_assert_char('o', ==, framebuffer[80 * 2 + 2]);
    munit_assert_char('r', ==, framebuffer[80 * 2 + 4]);
    munit_assert_char('l', ==, framebuffer[80 * 2 + 6]);
    munit_assert_char('d', ==, framebuffer[80 * 2 + 8]);

    return MUNIT_OK;
}

MunitTest console_HelloWorld_tests[] = 
{
    { "/console_should_write_hello_world_with_printstring_statement_test", console_should_write_hello_world_with_printstring_statement_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_write_hello_world_with_printstring_statements_test", console_should_write_hello_world_with_printstring_statements_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_write_hello_CRLF_world_with_printstring_statement_test", console_should_write_hello_CRLF_world_with_printstring_statement_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_write_hello_CRLF_world_with_printstring_statements_test", console_should_write_hello_CRLF_world_with_printstring_statements_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_write_hello_CRLF_world_with_printline_statements_test", console_should_write_hello_CRLF_world_with_printline_statements_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* Mark the end of the array with an empty entry */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};