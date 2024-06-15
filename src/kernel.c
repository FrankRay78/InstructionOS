#include "kernel.h"


// Assumes VGA text mode 7 (80 x 25)
// ref: https://en.wikipedia.org/wiki/VGA_text_mode

#define CONSOLE_MAX_WIDTH 80
#define CONSOLE_MAX_HEIGHT 25
#define CONSOLE_BYTES_PER_PIXEL 2
#define CONSOLE_VIDEO_ADDRESS 0xb8000
#define CONSOLE_WHITE_ON_BLUE  0x1f


void debug_writechar(char c)
{
    /*
    __asm__ ("movb %0, %%al\n\t"
            "outb %%al, $0xe9"
    :
    : "r" (c));
    */

    //asm( "outb %%al, $0xe9" :: "a"(c) );
    asm( "outb %0, $0xe9" :: "a"(c) );
}

void debug(char* message)
{
/*
    for (int i = 0; message[i] != 0; i++)
    {
        __asm__("movb %0, %%al\n\t"
                "outb %%al, $0xe9"
        :
        : "r" (message[i]));
    }
*/

    //debug_writechar(' ');

    for (int i = 0; message[i] != 0; i++)
    {
        if (i == 0)
        {
            debug_writechar(' ');
        }

        debug_writechar(message[i]);

        //volatile char c = message[i];
        //debug_writechar(c);
    }

    //debug_writechar(' ');

/*    debug_writechar('\0');
    debug_writechar(NULL);
    debug_writechar((void*)0);*/
}


asmlinkage int kernel_main()
{
    console_initialise(CONSOLE_MAX_WIDTH, CONSOLE_MAX_HEIGHT, CONSOLE_BYTES_PER_PIXEL, (unsigned char*)CONSOLE_VIDEO_ADDRESS, (char)CONSOLE_WHITE_ON_BLUE);


    console_clear();
    //console_setcursor(0, 0);

    // Write to QEMU's debug port
    /*mov al, 'F'
    out 0xe9, al*/

    // GCC uses AT&T/UNIX asm syntax (not Intel)
    // ref: https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html#toc3

    /*
    __asm__("movb $'F', %al\n\t"
            "outb %al, $0xe9\n\t");

    char c = 'W';

    __asm__("movb %0, %%al\n\t"
            "outb %%al, $0xe9"
            :
            : "r" (c));
    */

    debug("Monkey lives here");
    debug("Snail lives here");

    debug("aaa");
    //debug_writechar((char)'\0');
    debug_writechar((char)'\n');
    debug("bbb");
    /*debug_writechar(NULL);
    debug("ccc");
    debug_writechar((void*)0);
    debug("ddd");*/

    console_printstring("\n InstructionOS");


    return 0;
}

