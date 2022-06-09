all:test.objdump test.lof

include ../Makefile.common

test.o:test.S

test.elf:test.o
	sh64-elf-ld -o $@ $< -T ../default.x --oformat elf64-sh64

test.objdump:test.elf

test.lof:test.log
