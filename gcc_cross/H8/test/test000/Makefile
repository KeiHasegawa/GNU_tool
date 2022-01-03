all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o test.x
	h8300-elf-ld -o $@ $< -T $(basename $<).x

test.lof:test.log
