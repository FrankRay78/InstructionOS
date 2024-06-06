#include "console_tests.h"

MunitResult console_should_printstring_test(const MunitParameter params[], void* user_data_or_fixture) 
{
    // Calculate the total size needed for the framebuffer
    //size_t framebuffer_size = width * height * bytes_per_pixel;
    //size_t framebuffer_size = 2;

    // Allocate memory for the framebuffer
    //framebuffer = (unsigned char*)malloc(framebuffer_size);

    unsigned char fb[10];

    framebuffer = fb;

    printstring("Hello");
    
    munit_assert_char(framebuffer[0], ==, 'H');
    munit_assert_char(framebuffer[1], ==, WHITE_ON_BLUE);
    munit_assert_char(framebuffer[2], ==, 'e');
    munit_assert_char(framebuffer[3], ==, WHITE_ON_BLUE);
    munit_assert_char(framebuffer[4], ==, 'l');
    munit_assert_char(framebuffer[5], ==, WHITE_ON_BLUE);
    munit_assert_char(framebuffer[6], ==, 'l');
    munit_assert_char(framebuffer[7], ==, WHITE_ON_BLUE);
    munit_assert_char(framebuffer[8], ==, 'o');
    munit_assert_char(framebuffer[9], ==, WHITE_ON_BLUE);

    return MUNIT_OK;
}

MunitResult console_should_printchar_test(const MunitParameter params[], void* user_data_or_fixture) 
{
    // Calculate the total size needed for the framebuffer
    //size_t framebuffer_size = width * height * bytes_per_pixel;
    //size_t framebuffer_size = 2;

    // Allocate memory for the framebuffer
    //framebuffer = (unsigned char*)malloc(framebuffer_size);

    unsigned char fb[10];

    framebuffer = fb;

    printchar('H');
    
    munit_assert_char(framebuffer[0], ==, 'H');
    munit_assert_char(framebuffer[1], ==, WHITE_ON_BLUE);

    return MUNIT_OK;
}

MunitTest console_tests[] = 
{
    { "/console_should_printstring_test", console_should_printstring_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/console_should_printchar_test", console_should_printchar_test, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    /* Mark the end of the array with an empty entry */
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};