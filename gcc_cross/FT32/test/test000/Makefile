all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	ft32-elf-ld -o $@ $< -T test.x

test.lof:test.log

