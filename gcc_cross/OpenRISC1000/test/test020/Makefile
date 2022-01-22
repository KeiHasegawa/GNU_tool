all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../default.o subr.o
	or1k-elf-ld -o $@ ../default.o $< subr.o -T ../default.x

test.lof:test.log
