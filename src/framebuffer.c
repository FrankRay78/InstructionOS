#include "framebuffer.h"


// A byte pointer to the start of video memory
unsigned char* buffer;


void framebuffer_initialise(unsigned char* framebuffer)
{
    buffer = framebuffer;
}

void framebuffer_writechar(int index, char c) 
{
    buffer[index] = c;
}

void framebuffer_copy(int sourcePosition, int destinationPosition, int length)
{
    for (int i = 0; i < length; i++)
    {
        buffer[destinationPosition + i] = buffer[sourcePosition + i];
    }
}