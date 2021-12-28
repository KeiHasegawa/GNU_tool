all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o test.x
	or1k-elf-ld -o $@ test.o -T test.x -Map test.map

test.lof:test.log

