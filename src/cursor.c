#include "cursor.h"
#include "port.h"
#include <stdint.h>


// Manipulating the Text-mode Cursor
// ref: https://www.khoury.northeastern.edu/home/skotthe/classes/cs5600/fall/2016/pintos/doc/standards/freevga/vga/textcur.htm

#define VGA_ADDRESS_REGISTER 0x3D4
#define VGA_DATA_REGISTER 0x3D5


void cursor_show()
{
    port_writechar(0x0A, VGA_ADDRESS_REGISTER);
    port_writechar(0x00, VGA_DATA_REGISTER);
}

void cursor_hide()
{
    port_writechar(0x0A, VGA_ADDRESS_REGISTER);
    port_writechar(0x20, VGA_DATA_REGISTER);
}

void cursor_setposition(int x, int y, int width)
{
    uint16_t pos = y * width + x;

    port_writechar(0x0F, VGA_ADDRESS_REGISTER);
    port_writechar((uint8_t)(pos & 0xFF), VGA_DATA_REGISTER);
    port_writechar(0x0E, VGA_ADDRESS_REGISTER);
    port_writechar((uint8_t)((pos >> 8) & 0xFF), VGA_DATA_REGISTER);
}


Cursor create_cursor() {
    Cursor cursor;
    
    cursor.Show = cursor_show;
    cursor.Hide = cursor_hide;
    cursor.SetPosition = cursor_setposition;

    return cursor;
}
