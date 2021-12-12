all:test003.objdump test003.lof

include ../Makefile.common

test003.elf:test003.o test003.x
	m32r-elf-ld -o $@ test003.o -T test003.x -Map test003.map

test003.lof:test003.log

