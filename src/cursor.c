#include "cursor.h"
#include "shared/port.h"
#include <stdint.h>


// Manipulating the Text-mode Cursor
// ref: https://www.khoury.northeastern.edu/home/skotthe/classes/cs5600/fall/2016/pintos/doc/standards/freevga/vga/textcur.htm

#define VGA_ADDRESS_REGISTER 0x3D4
#define VGA_DATA_REGISTER 0x3D5


void cursor_show()
{
    port_writechar(VGA_ADDRESS_REGISTER, 0x0A);
    port_writechar(VGA_DATA_REGISTER, 0x00);
}

void cursor_hide()
{
    port_writechar(VGA_ADDRESS_REGISTER, 0x0A);
    port_writechar(VGA_DATA_REGISTER, 0x20);
}

void cursor_setposition(int x, int y, int width)
{
    uint16_t pos = y * width + x;

    port_writechar(VGA_ADDRESS_REGISTER, 0x0F);
    port_writechar(VGA_DATA_REGISTER, (uint8_t)(pos & 0xFF));
    port_writechar(VGA_ADDRESS_REGISTER, 0x0E);
    port_writechar(VGA_DATA_REGISTER, (uint8_t)((pos >> 8) & 0xFF));
}


Cursor create_cursor() {
    Cursor cursor;
    
    cursor.Show = cursor_show;
    cursor.Hide = cursor_hide;
    cursor.SetPosition = cursor_setposition;

    return cursor;
}
