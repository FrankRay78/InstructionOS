#include "kernel.h"

asmlinkage int kernel_main()
{
    printstring("Hello World!");

	return 0;
}