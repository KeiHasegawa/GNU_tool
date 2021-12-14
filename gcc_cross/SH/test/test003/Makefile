all:test003.objdump test003.lof

include ../Makefile.common

test003.elf:test003.c
	sh-elf-gcc -o $@ $< -g -m2a

test003.lof:test003.log
