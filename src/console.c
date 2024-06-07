#include "console.h"


// A byte pointer to the start of video memory
unsigned char* console_framebuffer;
char console_attribute;
int console_width;
int console_height;

int offset = 0;


void console_initialise(int width, int height, int bytes_per_pixel, unsigned char* framebuffer, char attribute)
{
	console_width = width;
	console_height = height;
	console_framebuffer = framebuffer;
	console_attribute = attribute;
}

void console_clear()
{
	offset = 0;

	for (int i = 0; i < console_width * console_height; i++)
	{
		console_printchar(' ');
	}

	offset = 0;
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
    console_framebuffer[offset++]=c;
    console_framebuffer[offset++]=console_attribute;
}