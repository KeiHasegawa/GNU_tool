all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../default.o
	cr16-elf-ld -o $@ ../default.o test.o \
	-T ../default.x --defsym _heap=0x1000

test.lof:test.log
