all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	bfin-elf-ld -o $@ test.o -T ../default.x

test.lof:test.log
