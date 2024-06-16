#include "kernel.h"
#include "console.h"
#include "debug.h"


// Assumes VGA text mode 7 (80 x 25)
// ref: https://en.wikipedia.org/wiki/VGA_text_mode

#define CONSOLE_MAX_WIDTH 80
#define CONSOLE_MAX_HEIGHT 25
#define CONSOLE_BYTES_PER_PIXEL 2
#define CONSOLE_VIDEO_ADDRESS 0xb8000
#define CONSOLE_WHITE_ON_BLUE  0x1f


asmlinkage int kernel_main()
{
    debug_message("Initialising console");

    console_initialise(CONSOLE_MAX_WIDTH, CONSOLE_MAX_HEIGHT, CONSOLE_BYTES_PER_PIXEL, (unsigned char*)CONSOLE_VIDEO_ADDRESS, (char)CONSOLE_WHITE_ON_BLUE);


    debug_message("Clearing console");

    console_clear();


    debug_message("Drawing welcome screen");

    console_printstring("\n InstructionOS");


    debug_message("Ready");


    return 0;
}

