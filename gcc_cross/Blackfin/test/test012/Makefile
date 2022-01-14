all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o start.o
	bfin-elf-ld -o $@ start.o test.o -T ../default.x

test.lof:test.log
