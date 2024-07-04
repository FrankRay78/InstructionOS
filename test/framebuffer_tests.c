#include "framebuffer_tests.h"
#include "../src/display/framebuffer.h"

MunitResult framebuffer_should_contain_hello_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[5];
    framebuffer_initialise(framebuffer);

    // When
    framebuffer_writechar(0, 'H');
    framebuffer_writechar(1, 'e');
    framebuffer_writechar(2, 'l');
    framebuffer_writechar(3, 'l');
    framebuffer_writechar(4, 'o');

    // Then
    munit_assert_char('H', ==, framebuffer[0]);
    munit_assert_char('e', ==, framebuffer[1]);
    munit_assert_char('l', ==, framebuffer[2]);
    munit_assert_char('l', ==, framebuffer[3]);
    munit_assert_char('o', ==, framebuffer[4]);

    return MUNIT_OK;
}

MunitResult framebuffer_should_copy_test(const MunitParameter params[], void* user_data_or_fixture)
{
    // Given
    unsigned char framebuffer[5];
    framebuffer_initialise(framebuffer);
    
    framebuffer_writechar(0, 'H');
    framebuffer_writechar(1, 'e');
    framebuffer_writechar(2, 'l');
    framebuffer_writechar(3, 'l');
    framebuffer_writechar(4, 'o');

    // When
    framebuffer_copy(3, 0, 2);

    // Then
    munit_assert_char('l', ==, framebuffer[0]);
    munit_assert_char('o', ==, framebuffer[1]);
    munit_assert_char('l', ==, framebuffer[2]);
    munit_assert_char('l', ==, framebuffer[3]);
    munit_assert_char('o', ==, framebuffer[4]);

    return MUNIT_OK;
}

MunitTest framebuffer_tests[] = 
{
    { "/framebuffer_should_contain_hello_test", framebuffer_should_contain_hello_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/framebuffer_should_copy_test", framebuffer_should_copy_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* Mark the end of the array with an empty entry */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};