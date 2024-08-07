#include "interrupt.h"
#include "../shared/port.h"
#include <stdint.h>


// The following code was inspired by Arjuns Reedharan excellent write up,
// "Kernels 201 - Let’s write a Kernel with keyboard and screen support"
// ref: https://arjunsreedharan.org/post/99370248137/kernels-201-lets-write-a-kernel-with-keyboard


// Prototypes
void idt_add_entry(uint8_t index, void (*handler)(void));
void idt_load_descriptor();
void pic_initialise();
void pic_set_interrupt_mask(uint8_t mask);
void pic_send_end_of_interrupt();


void interrupt_initialise()
{
    pic_initialise();
}

void interrupt_add_handler(uint8_t index, void (*handler)(void))
{
    idt_add_entry(index, handler);
}

void interrupt_set_mask(uint8_t mask)
{
    pic_set_interrupt_mask(mask);
}

void interrupt_enable_interrupts()
{
    idt_load_descriptor();

    // Enable interrupts
    asm volatile("sti" : : );
}

void interrupt_disable_interrupts()
{
    // Disable interrupts
    asm volatile("cli" : : );
}

void interrupt_send_end_of_interrupt()
{
    pic_send_end_of_interrupt();
}




//
// IDT
//

// Handling Interrupts
// ref: https://github.com/josehu07/hux-kernel/wiki/07.-Handling-Interrupts

// External Device Support
// ref: https://github.com/josehu07/hux-kernel/wiki/08.-External-Device-Support


#define IDT_SIZE 256
#define KERNEL_CODE_SEGMENT (1 << 3)
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


static IDT_entry IDT[IDT_SIZE];
static IDT_ptr idt_ptr;


void idt_add_entry(uint8_t index, void (*handler)(void)) 
{
    unsigned long handler_address = (unsigned long)handler;

    IDT[index].offset_lowerbits = handler_address & 0xffff;
    IDT[index].selector = KERNEL_CODE_SEGMENT;
    IDT[index].zero = 0;
    IDT[index].type_attr = INTERRUPT_GATE;
    IDT[index].offset_higherbits = (handler_address & 0xffff0000) >> 16;
}

void idt_load_descriptor() 
{
    // Populate the IDT descriptor
    idt_ptr.limit = sizeof(IDT) - 1;
    idt_ptr.base = (unsigned long)IDT;

    // Load the IDT
    asm volatile("lidt (%0)" : : "r" (&idt_ptr));
}



//
// PIC
//

// 8259 Programmable Interrupt Controller (PIC)
// ref: https://stanislavs.org/helppc/8259.html


#define PIC1          0x20     // Master PIC base address
#define PIC2          0xA0     // Slave PIC base address
#define PIC1_COMMAND (PIC1)
#define PIC1_DATA    (PIC1+1)
#define PIC2_COMMAND (PIC2)
#define PIC2_DATA    (PIC2+1)

#define PIC_EOI       0x20     // End-of-interrupt command


void pic_initialise() 
{
    // PIC Initialisation
    // ref: https://wiki.osdev.org/8259_PIC


    // ICW1 - Begin initialization
    port_writechar(PIC1_COMMAND, 0x11);
    port_writechar(PIC2_COMMAND, 0x11);

    // ICW2 - Remap offset address of IDT
    // In x86 protected mode, we have to remap the PICs beyond 0x20 because
    // Intel have designated the first 32 interrupts as "reserved" for cpu exceptions
    port_writechar(PIC1_DATA, 0x20);
    port_writechar(PIC2_DATA, 0x28);

    // ICW3 - Disable cascading
    port_writechar(PIC1_DATA, 0x00);
    port_writechar(PIC2_DATA, 0x00);

    // ICW4 - Environment info
    port_writechar(PIC1_DATA, 0x01);
    port_writechar(PIC2_DATA, 0x01);
    // PIC remapping finished


    // Disable all IRQ lines
    port_writechar(PIC1_DATA, 0xff);
    port_writechar(PIC2_DATA, 0xff);
}

void pic_set_interrupt_mask(uint8_t mask) 
{
    port_writechar(PIC1_DATA, mask);
}

void pic_send_end_of_interrupt()
{
    port_writechar(PIC1_COMMAND, PIC_EOI);
}