#include "kernel.h"

asmlinkage int kernel_main()
{
    clear();
    
    printstring("Hello World!");

	return 0;
}