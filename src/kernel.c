#include "kernel.h"


// Assumes VGA text mode 7 (80 x 25)
// ref: https://en.wikipedia.org/wiki/VGA_text_mode

#define CONSOLE_MAX_WIDTH 80
#define CONSOLE_MAX_HEIGHT 25
#define CONSOLE_BYTES_PER_PIXEL 2
#define CONSOLE_VIDEO_ADDRESS 0xb8000
#define CONSOLE_WHITE_ON_BLUE  0x1f


asmlinkage int kernel_main()
{
    console_initialise(CONSOLE_MAX_WIDTH, CONSOLE_MAX_HEIGHT, CONSOLE_BYTES_PER_PIXEL, (unsigned char*)CONSOLE_VIDEO_ADDRESS, (char)CONSOLE_WHITE_ON_BLUE);


    console_clear();
    
    console_printstring("Hello World!");


    /*
    //Ascii art courtesy of https://www.asciiart.eu/text-to-ascii-art
    //Doom font, width 80

    console_printline("                                                                         ");
    console_printline("    _____           _                   _   _             _____ _____    ");
    console_printline("   |_   _|         | |                 | | (_)           |  _  /  ___|   ");
    console_printline("     | |  _ __  ___| |_ _ __ _   _  ___| |_ _  ___  _ __ | | | \\ `--.    ");
    console_printline("     | | | '_ \\/ __| __| '__| | | |/ __| __| |/ _ \\| '_ \\| | | |`--. \\   ");
    console_printline("    _| |_| | | \\__ \\ |_| |  | |_| | (__| |_| | (_) | | | \\ \\_/ /\\__/ /   ");
    console_printline("   |_____|_| |_|___/\\__|_|   \\__,_|\\___|\\__|_|\\___/|_| |_|\\___/\\____/    ");
    */


    return 0;
}
