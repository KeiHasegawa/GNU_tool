all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	m32c-elf-ld -o $@ $< -T ../default.x

test.lof:test.log
