all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o start.o
	lm32-elf-ld -o $@ start.o $< -T ../default.x

test.lof:test.log
