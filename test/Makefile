
# Make implicit variables for compilation
HEADERS   = $(shell find .. -name "*.h")
C_SOURCES = $(shell find .. -name "*.c" | grep -v "../src.*/kernel.c")

OBJ=${C_SOURCES:.c=.o}

CC_FLAGS= -std=gnu11 -Wall -Wextra -Werror -g -Wno-unused-parameter
CC=gcc

LD_FLAGS= -std=gnu11 -Wall -Wextra -Werror -g -Wno-unused-parameter
LD=gcc


#
# Build and run the unit tests
#
run: build
	./main

build: main

main: $(OBJ)
	$(LD) -o main $(OBJ) $(LD_FLAGS)

%.o : %.c ${HEADERS}
	$(CC) -c $< -o $@ $(CC_FLAGS)


clean:
	find .. -name "*.o" -type f -delete
	find .. -name "*.bin" -type f -delete
	rm -fd main

.PHONY: clean