all:test007.objdump test007.lof

include ../Makefile.common

test007.elf:test007.o test007.x
	m68hc11-elf-ld -o test007.elf test007.o -T test007.x -Map test007.map

test007.lof:test007.log
