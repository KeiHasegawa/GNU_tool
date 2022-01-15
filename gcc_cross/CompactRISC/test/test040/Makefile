all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o start.o
	cr16-elf-ld -o $@ start.o $< -T ../default.x

test.lof:test.log
