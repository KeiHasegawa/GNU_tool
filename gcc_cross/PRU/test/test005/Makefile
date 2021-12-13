all:test005.objdump test005.lof

include ../Makefile.common

test005.elf:test005.o test005.x
	pru-elf-ld -o $@ test005.o -T test005.x -Map test005.map

test005.lof:test005.log
