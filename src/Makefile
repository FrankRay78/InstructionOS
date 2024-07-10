SHELL := /bin/bash


# Make implicit variables for compilation
HEADERS   = $(shell find . -name "*.h")
C_SOURCES = $(shell find . -name "*.c")
OBJ=${C_SOURCES:.c=.o}

# Dynamically determine include directories for NASM
ASM_INCLUDE=$(shell find . -name "*.s" -exec dirname {} \; | sort -u | sed 's/^/-I /')
ASM_SOURCES=$(shell find . -name "*.s")
ASM_OBJ=${ASM_SOURCES:.s=.o}

CC_FLAGS= -std=gnu11 -ffreestanding -nostdlib -O2 -lgcc -Wall -Wextra -Werror -g -Wno-unused-parameter
CC=~/opt/cross/bin/i686-elf-gcc

LD_TEMPLATE= -T $(shell find . -name "linkertemplate.ld")
LD_FLAGS= -std=gnu11 -ffreestanding -nostdlib -O2 -lgcc -Wall -Wextra -Werror -g -Wno-unused-parameter
LD=~/opt/cross/bin/i686-elf-gcc


#
# Build and run the kernel
#
run: build
	#qemu-system-i386 -kernel kernel.bin -no-reboot -no-shutdown -monitor stdio
	qemu-system-i386 -kernel kernel.bin -no-reboot -no-shutdown -debugcon stdio
	#qemu-system-i386 -kernel kernel.bin -no-reboot -no-shutdown -debugcon stdio -d int #qemu-system-i386 -d help | more
	#qemu-system-i386 -kernel kernel.bin -no-reboot -no-shutdown -debugcon file:debugcon.txt

build: kernel.bin

kernel.bin: $(ASM_OBJ) $(OBJ)
	$(LD) $(LD_TEMPLATE) -o kernel.bin $(ASM_OBJ) $(OBJ) $(LD_FLAGS)

%.o: %.s
	nasm -f elf32 $(ASM_INCLUDE) $< -o $@

%.o : %.c ${HEADERS}
	$(CC) -c $< -o $@ $(CC_FLAGS)


clean:
	find . -name "*.o" -type f -delete
	find . -name "*.bin" -type f -delete

.PHONY: clean