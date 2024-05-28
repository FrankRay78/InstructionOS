
nasm -f elf32 -o bootloader.o bootloader.asm

i686-elf-gcc -T linkertemplate.ld -o kernel.bin -ffreestanding -O2 -nostdlib bootloader.o -lgcc

qemu-system-i386 -kernel kernel.bin -no-reboot -no-shutdown -monitor stdio