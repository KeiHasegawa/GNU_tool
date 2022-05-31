all:test.objdump test.lof

include ../Makefile.common

test.o:test.S
	ns32k-elf-as -o $@ $< -g

test.elf:test.o ../default.o
	ns32k-elf-ld -o $@ $< -T ../default.x

test.lof:test.log

