#include "interrupt.h"
#include "port.h"


// The following code was inspired by Arjuns Reedharan excellent write up,
// "Kernels 201 - Let’s write a Kernel with keyboard and screen support"
// ref: https://arjunsreedharan.org/post/99370248137/kernels-201-lets-write-a-kernel-with-keyboard

// Other good reference material:

// Handling Interrupts
// ref: https://github.com/josehu07/hux-kernel/wiki/07.-Handling-Interrupts

// External Device Support
// ref: https://github.com/josehu07/hux-kernel/wiki/08.-External-Device-Support

// 8259 Programmable Interrupt Controller (PIC)
// ref: https://stanislavs.org/helppc/8259.html


#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8e


typedef struct {
	unsigned short offset_lowerbits;
	unsigned short selector;
	unsigned char zero;
	unsigned char type_attr;
	unsigned short offset_higherbits;
} __attribute__((packed)) IDT_entry;

typedef struct {
	unsigned short limit; // Length in bytes - 1
	unsigned long base;
} __attribute__((packed)) IDT_ptr;


#define KERNEL_CODE_SEGMENT_OFFSET (1 << 3) //KERNEL_CS
//extern unsigned int CODE_SEGMENT;
extern void load_idt(IDT_ptr *idt_ptr);
extern void keyboard_handler(void);


void interrupt_initialise()
{
	IDT_entry IDT[IDT_SIZE] = {0};
	IDT_ptr idt_ptr;

	unsigned long keyboard_address;
	
	// Populate IDT entry of keyboard's interrupt
	keyboard_address = (unsigned long)keyboard_handler;
	IDT[0x21].offset_lowerbits = keyboard_address & 0xffff;
	IDT[0x21].selector = KERNEL_CODE_SEGMENT_OFFSET;
	IDT[0x21].zero = 0;
	IDT[0x21].type_attr = INTERRUPT_GATE;
	IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;


	// Ports   PIC1 PIC2
	// Command 0x20 0xA0
	// Data	   0x21 0xA1

    // TODO: Define constants for PIC1 & 2, as per:
    // ref: https://github.com/dreamportdev/Osdev-Notes/blob/master/02_Architecture/07_APIC.md
    // ref: https://wiki.osdev.org/8259_PIC

	// ICW1 - begin initialization
	port_writechar(0x20, 0x11);
	port_writechar(0xA0, 0x11);

	// ICW2 - remap offset address of IDT
	// In x86 protected mode, we have to remap the PICs beyond 0x20 because
	// Intel have designated the first 32 interrupts as "reserved" for cpu exceptions
	port_writechar(0x21, 0x20);
	port_writechar(0xA1, 0x28);

	// ICW3 - setup cascading
	port_writechar(0x21, 0x00);
	port_writechar(0xA1, 0x00);

    //ref: https://github.com/josehu07/hux-kernel/wiki/08.-External-Device-Support
    /*port_writechar(0x21, 0x04);
    port_writechar(0xA1, 0x02);*/

	// ICW4 - environment info
	port_writechar(0x21, 0x01);
	port_writechar(0xA1, 0x01);
	// Initialization finished


	// Disable all IRQ lines
	port_writechar(0x21, 0xff);
	port_writechar(0xA1, 0xff);


	// Populate the IDT descriptor
	idt_ptr.limit = sizeof(IDT) - 1;
	idt_ptr.base = (unsigned long)IDT;
	load_idt(&idt_ptr);
    /*asm volatile(
    	"lidt (%0)\n\t" 
    	"sti" //turn on interrupts
    	: : "r" (&idt_ptr));*/


	// Enable only IRQ1 (keyboard) - 0xFD is 11111101
	port_writechar(0x21 , 0xFD);
}