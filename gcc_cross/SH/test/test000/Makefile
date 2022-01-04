all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o test.x
	sh-elf-ld -o test.elf test.o -T test.x -Map test.map

test.lof:test.log
