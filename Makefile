
kernel.bin: 
	nasm -f elf32 -o src/bootloader.o src/bootloader.asm
	i686-elf-gcc -T src/linkertemplate.ld -o src/kernel.bin src/bootloader.o -ffreestanding -O2 -nostdlib -lgcc
	qemu-system-i386 -kernel src/kernel.bin -no-reboot -no-shutdown -monitor stdio

.PHONY: clean
clean:
	rm -fd src/*.o
	rm -fd src/*.bin