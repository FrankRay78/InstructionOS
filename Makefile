
kernel: 
	nasm -f elf32 -o src/bootloader.o src/bootloader.s
	i686-elf-gcc -c src/kernel.c -o src/kernel.o -ffreestanding -O2 -nostdlib -lgcc
	i686-elf-gcc -T src/linkertemplate.ld -o src/kernel.bin src/bootloader.o src/kernel.o -ffreestanding -O2 -nostdlib -lgcc
	qemu-system-i386 -kernel src/kernel.bin -no-reboot -no-shutdown -monitor stdio


clean:
	rm -fd src/*.o
	rm -fd src/*.bin


.PHONY: kernel clean