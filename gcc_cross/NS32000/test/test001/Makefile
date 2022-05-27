all:test.objdump test.lof

include ../Makefile.common

test.o:test.S

test.elf:test.o
	ns32k-elf-ld -o $@ $< -T ../default.x

test.objdump:test.elf

test.lof:test.log
