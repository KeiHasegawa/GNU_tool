all:test.objdump test.lof

include ../Makefile.common

start.o:start.S

test.o:test.c

test.elf:start.o test.o
	x86_64-elf-ld -o $@ start.o test.o -T test.x

test.lof:test.log

