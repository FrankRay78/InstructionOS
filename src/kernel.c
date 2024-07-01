#include "kernel.h"
#include "cursor.h"
#include "console.h"
#include "debug.h"
#include "interrupt.h"
//#include "port.h"


// Assumes VGA text mode 7 (80 x 25)
// ref: https://en.wikipedia.org/wiki/VGA_text_mode

#define CONSOLE_WIDTH 80
#define CONSOLE_HEIGHT 25
#define CONSOLE_VIDEO_ADDRESS 0xb8000
#define CONSOLE_WHITE_ON_BLUE  0x1f


asmlinkage int kernel_main()
{
    debug_message("Initialising");

    Cursor cursor = create_cursor();

    console_initialise(CONSOLE_WIDTH, CONSOLE_HEIGHT, (unsigned char*)CONSOLE_VIDEO_ADDRESS, (char)CONSOLE_WHITE_ON_BLUE, cursor);

    console_clear();

    console_printstring("\n InstructionOS");
    console_printstring("\n\n > ");

    interrupt_initialise();

    debug_message("Ready");

    return 0;
}

void kernel_keyboard_handler(void) 
{
    //TODO: Process the actual key press

    debug_writechar('.');
    //console_printchar('.');
}
