all:test000.objdump test000.lof

include ../Makefile.common

test000.elf:test000.o
	ft32-elf-ld -o $@ $< -T test000.x

test000.lof:test000.log

