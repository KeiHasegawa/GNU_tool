all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	iq2000-elf-ld -o $@ $< -T ../default.x

test.lof:test.log
