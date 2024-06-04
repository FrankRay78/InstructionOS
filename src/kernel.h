#pragma once

#include "console.h"


// On x86 32bit, all parameters should be passed through the stack
#define asmlinkage __attribute__((regparm(0)))