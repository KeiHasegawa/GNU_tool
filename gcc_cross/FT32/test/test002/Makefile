all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o start.o
	ft32-elf-ld -o $@ start.o $< $(LIBGCC) -T ../default.x

test.lof:test.log

