all:test003.objdump test003.lof

include ../Makefile.common

test003.elf:test003.o test003.x
	bfin-elf-ld -o $@ test003.o -T test003.x

test003.lof:test003.log
