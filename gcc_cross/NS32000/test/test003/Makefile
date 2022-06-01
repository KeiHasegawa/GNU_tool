all:test.objdump test.lof

include ../Makefile.common

test.s:test.c
	ns32k-elf-gcc -S $<

test.o:test.s
	ns32k-elf-as -o $@ $< -g

test.elf:test.o ../default.o

test.lof:test.log

