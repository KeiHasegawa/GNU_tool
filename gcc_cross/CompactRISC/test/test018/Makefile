all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../default.o
	cr16-elf-ld -o $@ ../default.o $< -T $(basename $<).x

test.lof:test.log
