all:test016.objdump test016.lof

include ../Makefile.common

test016.elf:start.o test016.o test016.x
	cr16-elf-ld -o $@ start.o test016.o \
	-T test016.x --defsym _heap=0x1000

test016.lof:test016.log
