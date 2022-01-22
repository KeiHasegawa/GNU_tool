all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	pru-elf-ld -o $@ $< -T ../default.x

test.lof:test.log

