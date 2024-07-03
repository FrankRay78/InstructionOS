# InstructionOS

A 32-bit, x86 operating system written in C. 

InstructionOS is a hobby operating system written with a particular interest in low-level, test-driven development and comprehensive unit test coverage integrated from the beginning, something other kernels severely lack. The kernel code is clean, well-structured and commented to maximise educational value.

## Features

* Kernel written in ANSI C
* Bootloader written in NASM assembly
* Build toolchain written in Makefiles
* Comprehensive unit test coverage
* Multiboot Specification v1 compliant
* Full 32-bit protected mode
* Basic keyboard handler
* VGA text mode 

## Progress

InstructionOS isn't a fully-fledged 'operating system' yet, but it does boot and is being actively developed. The obligatory screenshot (which is pretty underwhelming at the moment) is here:

![Screenshot from 2024-06-11 11-31-02](https://github.com/FrankRay78/InstructionOS/assets/52075808/025c2eed-c4d0-4208-a3d0-ce08dde13121)

## Playing with InstructionOS

InstructionOS is developed on Ubuntu running in VMWare workstation.

The following tools are required: gcc, nasm, make, QEMU (qemu-system-i386), C cross-compiler (i686-elf-gcc), hand-built using instructions from [here](https://wiki.osdev.org/GCC_Cross-Compiler).

`make` will boot the kernel in QEMU, having first built it using the C freestanding toolchain.

`make test` will run the unit tests, having first built the kernel and unit tests using the standard C99 toolchain.

`make clean` should be run before switching between these two commands, otherwise you'll get a linker failure (given the differing toolchains).

Additional targets exist in the main [Makefile](https://github.com/FrankRay78/InstructionOS/blob/main/Makefile), ideal for development IDE's with integrated Makefile support (eg. JetBrains CLion or Visual Studio Code).

## License

InstructionOS is free software licensed under the terms of the MIT License, see [LICENSE](https://github.com/FrankRay78/InstructionOS/blob/main/LICENSE) for more details.

## Credits

InstructionOS was created by Frank Ray, [Better Software UK](https://bettersoftware.uk).
