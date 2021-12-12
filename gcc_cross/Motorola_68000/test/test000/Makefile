all:test000.objdump test000.lof

include ../Makefile.common

test000.o:test000.S
	m68hc11-elf-as -o test000.o -g test000.S

test000.elf:test000.o test000.x
	m68hc11-elf-ld -o test000.elf test000.o -T test000.x -Map test000.map

test000.lof:test000.log
