#include "cursor.h"
#include "console.h"
#include "debug.h"
#include "interrupt.h"
//#include "port.h"


// On x86 32-bit, all parameters should be passed through the stack
#define asmlinkage __attribute__((regparm(0)))


// Assumes VGA text mode 7 (80 x 25)
// ref: https://en.wikipedia.org/wiki/VGA_text_mode

#define CONSOLE_WIDTH 80
#define CONSOLE_HEIGHT 25
#define CONSOLE_VIDEO_ADDRESS 0xb8000
#define CONSOLE_WHITE_ON_BLUE  0x1f


asmlinkage int kernel_main()
{
    debug_printline("Initialising");

    Cursor cursor = create_cursor();

    console_initialise(CONSOLE_WIDTH, CONSOLE_HEIGHT, (unsigned char*)CONSOLE_VIDEO_ADDRESS, (char)CONSOLE_WHITE_ON_BLUE, cursor);

    console_clear();

    console_printstring("\n InstructionOS");
    console_printstring("\n\n > ");

    interrupt_initialise();

    debug_printline("Ready");

    return 0;
}

void kernel_keyboard_handler(void) 
{
    //TODO: Process the actual key press

    debug_printchar('.');
    //console_printchar('.');
}
