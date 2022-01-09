all:test.objdump test.lof

include ../Makefile.common

test.o:test.S
	m68hc11-elf-as -o test.o -g test.S

test.elf:test.o
	m68hc11-elf-ld -o test.elf test.o -T ../default.x -Map test.map

test.lof:test.log
