#pragma once


// Initialise system interrupts
void interrupt_initialise(void (*keyboard_handler)(void));

void pic_send_end_of_interrupt();