#pragma once

#include "console.h"
#include "debug.h"


// On x86 32-bit, all parameters should be passed through the stack
#define asmlinkage __attribute__((regparm(0)))