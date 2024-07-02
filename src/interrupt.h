#pragma once

#include <stdint.h>


void idt_add_entry(uint8_t index, void (*handler)(void));
void idt_load_descriptor();
void pic_initialise();
void pic_keyboard_interrupt_enable();
void pic_send_end_of_interrupt();
