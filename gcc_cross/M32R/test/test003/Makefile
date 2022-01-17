all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	m32r-elf-ld -o $@ test.o -T ../default.x

test.lof:test.log

