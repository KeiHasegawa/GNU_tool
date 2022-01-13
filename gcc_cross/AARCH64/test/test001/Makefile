all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	aarch64-elf-ld -o $@ $< -T ../default.x

test.lof:test.log
