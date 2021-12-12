all:test004.objdump test004.lof

include ../Makefile.common

test004.elf:test004.o test004.x
	mips-elf-ld -o $@ test004.o -T test004.x -Map test004.map

test004.lof:test004.log
