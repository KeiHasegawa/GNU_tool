all:test.objdump test.lof

include ../Makefile.common

test.elf:test.c
	sh-elf-gcc -o $@ $< -g -m2a

test.lof:test.log
