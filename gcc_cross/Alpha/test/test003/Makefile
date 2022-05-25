all:test.objdump test.lof

include ../Makefile.common

test.o:test.S

test.elf:test.o test.x
	alpha-elf-ld -o $@ $< -T test.x

test.objdump:test.elf

test.lof:test.log
