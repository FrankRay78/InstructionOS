#include "cursor.h"
#include "console.h"
#include "debug.h"
#include "interrupt.h"
#include "keyboard_map.h"
#include "port.h"


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

    console_printstring("\n InstructionOS \n");
    console_printstring("\n > ");

    interrupt_initialise();

    debug_printline("Ready");

    return 0;
}



#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define ENTER_KEY_CODE 0x1C


void kernel_keyboard_handler(void) 
{
    unsigned char status;
    char keycode;


    status = port_readchar(KEYBOARD_STATUS_PORT);

    // Lowest bit of status will be set if buffer is not empty
    if (status & 0x01) 
    {
        keycode = port_readchar(KEYBOARD_DATA_PORT);

        if (keycode >= 0)
        {
            if (keycode == ENTER_KEY_CODE)
            {
                console_printstring("\n > ");
            }
            else
            {
                console_printchar(keyboard_map[(unsigned char)keycode]);
            }
        }
    }


    pic_send_end_of_interrupt();
}
