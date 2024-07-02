#include "console.h"
#include "interrupt.h"
#include "keyboard.h"
#include "keyboard_map.h"
#include "port.h"
#include <stddef.h>


#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64
#define ENTER_KEY_CODE 0x1C



void keyboard_initialise(void (*keyboard_handler)(void))
{
    if (keyboard_handler == NULL)
        return;

    pic_initialise();

    idt_add_entry(0x21, keyboard_handler);

    idt_load_descriptor();

    pic_keyboard_interrupt_enable();
}


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