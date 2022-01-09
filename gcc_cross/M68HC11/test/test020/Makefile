all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o start.o
	m68hc11-elf-ld -o $@ start.o test.o $(LIBGCC) -T ../default.x

test.lof:test.log
