#include "port.h"


// How to Use Inline Assembly Language in C Code
// ref: https://gcc.gnu.org/onlinedocs/gcc/Using-Assembly-Language-with-C.html

// GCC uses AT&T/UNIX asm syntax (not Intel)
// ref: https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html#toc3


inline uint8_t port_readchar(uint16_t port)
{
    uint8_t data;
    asm volatile("inb %w1, %b0" : "=a"(data) : "d"(port));
    return data;
}

inline void port_writechar(uint16_t port, uint8_t data)
{
    asm volatile("outb %b0, %w1" : : "a"(data), "d"(port));
}