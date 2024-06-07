
# Make implicit variables for compilation
HEADERS   = $(wildcard src/*.h)
C_SOURCES = $(wildcard src/*.c)
OBJ=${C_SOURCES:.c=.o}

ASM_SOURCES = $(wildcard src/*.s)
ASM_OBJ =${ASM_SOURCES:.s=.o}


CC_FLAGS= -ffreestanding -O2 -nostdlib -lgcc -Wall -Wextra -g
CC=i686-elf-gcc

LD_FLAGS= -ffreestanding -O2 -nostdlib -lgcc -Wall -Wextra -g
LD=i686-elf-gcc


run: build
	qemu-system-i386 -kernel src/kernel.bin -no-reboot -no-shutdown -monitor stdio

build: src/kernel.bin

src/kernel.bin: $(ASM_OBJ) $(OBJ)
	$(LD) -T src/linkertemplate.ld -o src/kernel.bin $(ASM_OBJ) $(OBJ) $(LD_FLAGS)

%.o: %.s
	nasm -f elf32 $< -o $@

%.o : %.c ${HEADERS} 
	$(CC) -c $< -o $@ $(CC_FLAGS)


clean:
	rm -fd src/*.o
	rm -fd src/*.bin


.PHONY: clean