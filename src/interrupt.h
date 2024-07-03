#pragma once

#include <stdint.h>


// Usage Notes
// -----------
// PIC master/slave cascading has been disabled
// Interrupt mask and EOI applies only to the master

void interrupt_initialise();
void interrupt_add_handler(uint8_t index, void (*handler)(void));
void interrupt_set_mask(uint8_t mask);
void interrupt_enable_interrupts();
void interrupt_disable_interrupts();
void interrupt_send_end_of_interrupt();