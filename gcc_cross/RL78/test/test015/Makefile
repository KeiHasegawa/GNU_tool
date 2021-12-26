all:test015.objdump test015.lof

include ../Makefile.common

test015.elf:test015.o
	rl78-elf-ld -o $@ $< -T $(basename $<).x

test015.lof:test015.log
