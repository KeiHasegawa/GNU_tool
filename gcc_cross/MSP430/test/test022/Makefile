all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o subr.o
	msp430-elf-ld -o $@ $< subr.o -T ../default.x

test.lof:test.log
