all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../default.o subr.o
	bfin-elf-ld -o $@ ../default.o $< subr.o -T ../default.x

test.lof:test.log
