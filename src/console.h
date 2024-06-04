#pragma once


#define VIDEO_ADDRESS 0xb8000
#define WHITE_ON_BLUE  0x1f


// Blanks the screen by writing the ASCII space character to each character cell
void Clear();

// Print a string to the current cursor position and then moves the cursor to the next line
void printline(char* s);

// Print a string to the current cursor position
void printstring(char* s);

// Print a character to the current cursor position
void printchar(char c);