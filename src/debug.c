#include "debug.h"
#include "port.h"
#include <stddef.h>


#define DEBUG_PORT 0xe9


void debug_writechar(char c)
{
    port_writechar(c, DEBUG_PORT);
}

void debug_message(char* message)
{
    if (message != NULL)
    {
        for (int i = 0; message[i] != 0; i++)
        {
            debug_writechar(message[i]);
        }

        debug_writechar('\n');
    }
}