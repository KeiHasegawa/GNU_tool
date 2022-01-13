all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o test.x
	arm-elf-ld -o $@ $< -T $(basename $<).x

test.lof:test.log
