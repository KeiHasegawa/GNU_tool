all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o test.x
	m32r-elf-ld -o test.elf test.o -T test.x -Map test.map

test.lof:test.log
