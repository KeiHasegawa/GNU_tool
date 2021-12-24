all:test013.objdump test013.lof

include ../Makefile.common

test013.elf:test013.o
	rl78-elf-ld -o $@ $< -T $(basename $<).x

test013.lof:test013.log
