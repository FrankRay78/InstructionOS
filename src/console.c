#include "console.h"
#include "framebuffer.h"
#include <stdbool.h>
#include <stdint.h>


int width;
int height;
char attribute;

// Cursor position
int column;
int row;


// Manipulating the Text-mode Cursor
// ref: https://www.khoury.northeastern.edu/home/skotthe/classes/cs5600/fall/2016/pintos/doc/standards/freevga/vga/textcur.htm

#define VGA_ADDRESS_REGISTER 0x3D4
#define VGA_DATA_REGISTER 0x3D5


void console_initialise(int console_width, int console_height, unsigned char* console_framebuffer, char console_attribute)
{
	width = console_width;
	height = console_height;
	attribute = console_attribute;

	framebuffer_initialise(console_framebuffer);

    // Initialise the cursor position
    column = 0;
    row = 0;
}

void console_writechar(char c) 
{
	// Calculate the positional index required for the linear framebuffer
	// Each character is represented by two bytes aligned as a 16-bit word
	// ref: https://en.wikipedia.org/wiki/VGA_text_mode#Data_arrangement

    framebuffer_writechar(row * width * 2 + column * 2, c);
    framebuffer_writechar(row * width * 2 + column * 2 + 1, attribute);
}

/*void console_setcursor_visibility(bool visible)
{
	unsigned char cursor_start_register_data;

	if (visible)
		cursor_start_register_data = 0x00;
	else
		cursor_start_register_data = 0x20;

    //Hide the terminal console
    asm("outb %b0, %w1" :: "a"(0x0A), "d"(0x3D4));
    asm("outb %b0, %w1" :: "a"(0x20), "d"(0x3D5));

    //asm("outb %0, %1" :: "a"((unsigned char)0x0A), "d"((unsigned short)0x3D4));
    //asm("outb %0, %1" :: "a"((unsigned char)0x20), "d"((unsigned short)0x3D5));
}*/

void console_cursor_show()
{
    asm("outb %b0, %w1" :: "a"(0x0A), "d"(VGA_ADDRESS_REGISTER));
    asm("outb %b0, %w1" :: "a"(0x00), "d"(VGA_DATA_REGISTER));
}

void console_cursor_hide()
{
    asm("outb %b0, %w1" :: "a"(0x0A), "d"(VGA_ADDRESS_REGISTER));
    asm("outb %b0, %w1" :: "a"(0x20), "d"(VGA_DATA_REGISTER));
}

void console_cursor_setposition(int x, int y)
{
    uint16_t pos = y * width + x;

    asm("outb %b0, %w1" :: "a"(0x0F), "d"(VGA_ADDRESS_REGISTER));
    asm("outb %b0, %w1" :: "a"((uint8_t)(pos & 0xFF)), "d"(VGA_DATA_REGISTER));
    asm("outb %b0, %w1" :: "a"(0x0E), "d"(VGA_ADDRESS_REGISTER));
    asm("outb %b0, %w1" :: "a"((uint8_t)((pos >> 8) & 0xFF)), "d"(VGA_DATA_REGISTER));
}

void console_clear()
{
	console_cursor_hide();

	// Reset the cursor position
	column = 0;
	row = 0;

	for (int i = 0; i < width * height; i++)
	{
		console_printchar(' ');
	}

	// Reset the cursor position
	column = 0;
	row = 0;

	console_cursor_show();
	console_cursor_setposition(1, 1);
}

void console_printline(char* s)
{
	console_printstring(s);
	console_printchar('\n');
}

void console_printstring(char* s)
{
	for (int i = 0; s[i] != 0; i++)
	{
		console_printchar(s[i]);
	}
}

void console_printchar(char c)
{
	// Scroll if the cursor has dropped off the bottom of the terminal
	if (row == height)
	{
	    framebuffer_copy(width * 2, 0, (height - 1) * width * 2);

	    row--;

	    // Blank the last line ready for writing to
	    for (int i = 0; i < width; i++)
	    {
	        console_writechar(' ');

	        // Move the cursor right by one character
	        column++;
	    }

	    // Move the cursor to the beginning of the current line
	    column = 0;
	}

	// Perform a CRLF if we encounter a Newline character
	if (c == '\n')
	{
	    column = 0;
	    row++;

	    return;
	}

	console_writechar(c);

	// Move the cursor right by one character
	column++;

	// Perform a CRLF when the cursor reaches the end of the terminal line
	// eg.column is 0 to 79, width = 80
	if (column == width)
	{
	    column = 0;
	    row++;
	}
}