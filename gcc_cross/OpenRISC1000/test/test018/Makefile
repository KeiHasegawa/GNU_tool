all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	or1k-elf-ld -o $@ test.o -T ../default.x

test.lof:test.log

