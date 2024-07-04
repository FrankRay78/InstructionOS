#pragma once

#include <stdint.h>


uint8_t port_readchar(uint16_t port);
void port_writechar(uint16_t port, uint8_t data);