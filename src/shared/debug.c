#include "debug.h"
#include "port.h"
#include <stddef.h>


#define DEBUG_PORT 0xe9


void debug_printchar(char c)
{
    port_writechar(DEBUG_PORT, c);
}

void debug_printline(char* message)
{
    if (message != NULL)
    {
        for (int i = 0; message[i] != 0; i++)
        {
            debug_printchar(message[i]);
        }

        debug_printchar('\n');
    }
}