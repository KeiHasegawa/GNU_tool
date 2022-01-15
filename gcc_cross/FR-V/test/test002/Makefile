all:test.elf test.lof

include ../Makefile.common

test.elf:test.o
	frv-elf-ld -o $@ $< -T ../default.x

test.lof:test.log
