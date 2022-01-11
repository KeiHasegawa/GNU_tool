all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../default.o subr.o
	m68hc11-elf-ld -o $@ ../default.o $< subr.o $(LIBGCC) -T ../default.x

test.lof:test.log
