#pragma once

#include "munit.h"
#include "../src/console.h"

extern MunitTest console_tests[];

MunitResult console_should_printchar_test(const MunitParameter params[], void* user_data_or_fixture);