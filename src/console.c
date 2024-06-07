#include "console.h"


// A byte pointer to the start of video memory
unsigned char* framebuffer;
char attribute;
int width;
int height;

// Cursor position
int column = 0;
int row = 0;


// Write directly to the video memory
void framebuffer_writechar(char c) 
{
	// Calculate the positional index required for the linear framebuffer
	// Each character is represented by two bytes aligned as a 16-bit word
	// ref: https://en.wikipedia.org/wiki/VGA_text_mode#Data_arrangement

    framebuffer[row * width * 2 + column * 2] = c;
    framebuffer[row * width * 2 + column * 2 + 1] = attribute;
}

void framebuffer_copy(int sourcePosition, int destinationPosition, int length)
{
    for (int i = 0; i < length; i++)
    {
        framebuffer[destinationPosition + i] = framebuffer[sourcePosition + i];
    }
}


void console_initialise(int console_width, int console_height, int console_bytes_per_pixel, unsigned char* console_framebuffer, char console_attribute)
{
	width = console_width;
	height = console_height;
	framebuffer = console_framebuffer;
	attribute = console_attribute;
}

void console_clear()
{
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
	        framebuffer_writechar(' ');

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

	framebuffer_writechar(c);

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
