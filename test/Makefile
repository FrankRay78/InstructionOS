
# Make implicit variables for compilation
HEADERS   = $(wildcard ../src/*.h *.h)
C_SOURCES = $(wildcard ../src/*.c *.c)
OBJ=${C_SOURCES:.c=.o}

CC_FLAGS= -std=c99 -Wall -Wextra -Werror -g -Wno-unused-parameter
CC=gcc

LD_FLAGS= -std=c99 -Wall -Wextra -Werror -g -Wno-unused-parameter
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
	rm -fd ../src/*.o
	rm -fd ../src/*.bin
	rm -fd *.o
	rm -fd main

.PHONY: clean