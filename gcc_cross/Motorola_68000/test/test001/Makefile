all:test001.objdump test001.lof

include ../Makefile.common

test001.elf:test001.o test001.x
	m68hc11-elf-ld -o test001.elf test001.o -T test001.x -Map test001.map

test001.lof:test001.log
