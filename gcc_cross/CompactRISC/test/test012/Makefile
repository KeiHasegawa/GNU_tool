all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../default.o test.x
	cr16-elf-ld -o $@ ../default.o $< -T test.x

test.lof:test.log
