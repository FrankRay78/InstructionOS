#include "debug.h"
#include <stddef.h>


#define DEBUG_PORT 0xe9


void debug_writechar(char c)
{
    // How to Use Inline Assembly Language in C Code
    // ref: https://gcc.gnu.org/onlinedocs/gcc/Using-Assembly-Language-with-C.html

    // GCC uses AT&T/UNIX asm syntax (not Intel)
    // ref: https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html#toc3
    
    asm( "outb %0, %1" :: "a"(c), "Nd"(DEBUG_PORT) );
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