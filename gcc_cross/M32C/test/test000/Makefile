all:test000.objdump test000.lof

include ../Makefile.common

test000.elf:test000.o test000.x
	m32c-elf-ld -o test000.elf test000.o -T test000.x -Map test000.map

test000.lof:test000.log
