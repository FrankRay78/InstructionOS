#include "cursor.h"
#include <stdbool.h>
#include <stdint.h>


// Manipulating the Text-mode Cursor
// ref: https://www.khoury.northeastern.edu/home/skotthe/classes/cs5600/fall/2016/pintos/doc/standards/freevga/vga/textcur.htm

#define VGA_ADDRESS_REGISTER 0x3D4
#define VGA_DATA_REGISTER 0x3D5


void cursor_show()
{
    asm("outb %b0, %w1" :: "a"(0x0A), "d"(VGA_ADDRESS_REGISTER));
    asm("outb %b0, %w1" :: "a"(0x00), "d"(VGA_DATA_REGISTER));
}

void cursor_hide()
{
    asm("outb %b0, %w1" :: "a"(0x0A), "d"(VGA_ADDRESS_REGISTER));
    asm("outb %b0, %w1" :: "a"(0x20), "d"(VGA_DATA_REGISTER));
}

void cursor_setposition(int x, int y, int width)
{
    uint16_t pos = y * width + x;

    asm("outb %b0, %w1" :: "a"(0x0F), "d"(VGA_ADDRESS_REGISTER));
    asm("outb %b0, %w1" :: "a"((uint8_t)(pos & 0xFF)), "d"(VGA_DATA_REGISTER));
    asm("outb %b0, %w1" :: "a"(0x0E), "d"(VGA_ADDRESS_REGISTER));
    asm("outb %b0, %w1" :: "a"((uint8_t)((pos >> 8) & 0xFF)), "d"(VGA_DATA_REGISTER));
}