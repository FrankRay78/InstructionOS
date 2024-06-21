#include "console.h"
#include "framebuffer.h"


// Prototypes
void console_writechar(char c);


int width;
int height;
char attribute;

// Cursor position
int column;
int row;

Cursor cursor;


void console_initialise(int console_width, int console_height, unsigned char* console_framebuffer, char console_attribute, Cursor console_cursor)
{
	width = console_width;
	height = console_height;
	attribute = console_attribute;
	cursor = console_cursor;

	framebuffer_initialise(console_framebuffer);

    // Initialise the cursor position
    column = 0;
    row = 0;
}

void console_clear()
{
	//cursor_hide();
	cursor.Hide();

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

	//cursor_show();
	//cursor_setposition(column, row, width);
	cursor.Show();
	cursor.SetPosition(column, row, width);
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
	// Perform a CRLF if we encounter a Newline character
	// otherwise write the character to the console

	if (c == '\n')
	{
		// Move the cursor to the beginning of the next row
	    column = 0;
	    row++;
	}
	else
	{
		// Write the character
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

	cursor.SetPosition(column, row, width);
}


// Private:

void console_writechar(char c) 
{
	// Calculate the positional index required for the linear framebuffer
	// Each character is represented by two bytes aligned as a 16-bit word
	// ref: https://en.wikipedia.org/wiki/VGA_text_mode#Data_arrangement

    framebuffer_writechar(row * width * 2 + column * 2, c);
    framebuffer_writechar(row * width * 2 + column * 2 + 1, attribute);
}
