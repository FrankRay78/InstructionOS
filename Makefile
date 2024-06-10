
# Recursive Use of make
# ref: https://www.gnu.org/software/make/manual/make.html#Recursion

boot:
	$(MAKE) -C src

test:
	$(MAKE) -C test

clean:
	rm -fd src/*.o
	rm -fd src/*.bin
	rm -fd test/*.o
	rm -fd test/main

.PHONY: boot test clean