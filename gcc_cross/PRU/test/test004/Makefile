all:test004.objdump test004.lof

include ../Makefile.common

test004.elf:test004.o test004.x
	pru-elf-ld -o $@ $< -T $(basename $<).x

test004.lof:test004.log
