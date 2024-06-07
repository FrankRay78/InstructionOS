#include "kernel.h"

asmlinkage int kernel_main()
{
    framebuffer = (unsigned char*)CONSOLE_VIDEO_ADDRESS;

    clear();
    
    printstring("Hello World!");


    //Ascii art courtesy of https://www.asciiart.eu/text-to-ascii-art
    //Doom font, width 80
    /*
    printline("                                                                         ");
    printline("    _____           _                   _   _             _____ _____    ");
    printline("   |_   _|         | |                 | | (_)           |  _  /  ___|   ");
    printline("     | |  _ __  ___| |_ _ __ _   _  ___| |_ _  ___  _ __ | | | \\ `--.    ");
    printline("     | | | '_ \\/ __| __| '__| | | |/ __| __| |/ _ \\| '_ \\| | | |`--. \\   ");
    printline("    _| |_| | | \\__ \\ |_| |  | |_| | (__| |_| | (_) | | | \\ \\_/ /\\__/ /   ");
    printline("   |_____|_| |_|___/\\__|_|   \\__,_|\\___|\\__|_|\\___/|_| |_|\\___/\\____/    ");
    */


    return 0;
}
