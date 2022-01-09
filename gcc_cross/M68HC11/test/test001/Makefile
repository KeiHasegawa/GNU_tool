all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	m68hc11-elf-ld -o test.elf test.o -T ../default.x

test.lof:test.log
