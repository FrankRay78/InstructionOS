#include "kernel.h"

asmlinkage int kernel_main()
{
    framebuffer = (unsigned char*)CONSOLE_VIDEO_ADDRESS;

    clear();
    
    printstring("Hello World!");

    return 0;
}
