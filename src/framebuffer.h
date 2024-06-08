#pragma once


// Initialise the framebuffer
void framebuffer_initialise(unsigned char* framebuffer);

// Write directly to the video memory
void framebuffer_writechar(int index, char c);

// Copy a specified number of bytes to a new location
void framebuffer_copy(int sourcePosition, int destinationPosition, int length);