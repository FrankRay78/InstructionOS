
# Recursive Use of make
# ref: https://www.gnu.org/software/make/manual/make.html#Recursion


# Short-hand targets for command line
boot:
	$(MAKE) -C src

test:
	$(MAKE) -C test


# Verbose targets for development IDE's

buildkernel:
	$(MAKE) -C src build

runkernel:
	$(MAKE) -C src run

buildtest:
	$(MAKE) -C test build

runtest:
	$(MAKE) -C test run


clean:
	find . -name "*.o" -type f -delete
	find . -name "*.bin" -type f -delete
	rm -fd test/main
	
.PHONY: boot test buildkernel runkernel buildtest runtest clean