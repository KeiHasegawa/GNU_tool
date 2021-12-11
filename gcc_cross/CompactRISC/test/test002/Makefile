all:test002.objdump test002.lof

include ../Makefile.common

test002.elf:test002.o test002.x
	cr16-elf-ld -o test002.elf test002.o -T test002.x

test002.lof:test002.log
