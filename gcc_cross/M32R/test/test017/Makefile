all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../default.x
	m32r-elf-ld -o test.elf test.o -T ../default.x

test.lof:test.log
