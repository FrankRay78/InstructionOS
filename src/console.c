#include "console.h"


//Create a byte pointer to the start of video memory
//unsigned char* framebuffer = (unsigned char*)VIDEO_ADDRESS;
unsigned char* framebuffer;

char attribute = (char)CONSOLE_WHITE_ON_BLUE;

int offset = 0;


void clear()
{
	offset = 0;

	for (int i = 0; i < CONSOLE_MAX_WIDTH * CONSOLE_MAX_HEIGHT; i++)
	{
		printchar(' ');
	}

	offset = 0;
}

void printline(char* s)
{
	printstring(s);
	printchar('\n');
}

void printstring(char* s)
{
	for (int i = 0; s[i] != 0; i++)
	{
		printchar(s[i]);
	}
}

void printchar(char c)
{
    framebuffer[offset++]=c;
    framebuffer[offset++]=attribute;
}