all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o test.x
	moxie-elf-ld -o $@ test.o -T test.x -Map test.map

test.lof:test.log
