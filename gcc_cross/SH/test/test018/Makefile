all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o test.x
	sh-elf-ld -o $@ $< -T ../default.x

test.lof:test.log
