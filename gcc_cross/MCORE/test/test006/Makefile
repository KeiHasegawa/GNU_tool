all:test006.objdump test006.lof

include ../Makefile.common

test006.elf:test006.o test006.x
	mcore-elf-ld -o $@ test006.o -T test006.x -Map test006.map

test006.lof:test006.log
