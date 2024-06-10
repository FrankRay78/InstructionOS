
# Make implicit variables for compilation
HEADERS   = $(wildcard *.h)
C_SOURCES = $(wildcard *.c)
OBJ=${C_SOURCES:.c=.o}

ASM_SOURCES = $(wildcard *.s)
ASM_OBJ =${ASM_SOURCES:.s=.o}

CC_FLAGS= -ffreestanding -O2 -nostdlib -lgcc -Wall -Wextra -g -Wno-unused-parameter
CC=i686-elf-gcc

LD_FLAGS= -ffreestanding -O2 -nostdlib -lgcc -Wall -Wextra -g -Wno-unused-parameter
LD=i686-elf-gcc


#
# Build and run the kernel
#
boot: build
	qemu-system-i386 -kernel kernel.bin -no-reboot -no-shutdown -monitor stdio

build: kernel.bin

kernel.bin: $(ASM_OBJ) $(OBJ)
	$(LD) -T linkertemplate.ld -o kernel.bin $(ASM_OBJ) $(OBJ) $(LD_FLAGS)

%.o: %.s
	nasm -f elf32 $< -o $@

%.o : %.c ${HEADERS}
	$(CC) -c $< -o $@ $(CC_FLAGS)


clean:
	rm -fd *.o
	rm -fd *.bin

.PHONY: clean