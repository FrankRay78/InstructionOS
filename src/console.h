#pragma once

#include "framebuffer.h"


// Initialise the virtual console
void console_initialise(int width, int height, int bytes_per_pixel, unsigned char* framebuffer, char attribute);

// Blank the screen by writing the ASCII space character to each character cell
void console_clear();

// Print a string to the current cursor position and then moves the cursor to the next line
void console_printline(char* s);

// Print a string to the current cursor position
void console_printstring(char* s);

// Print a character to the current cursor position
void console_printchar(char c);