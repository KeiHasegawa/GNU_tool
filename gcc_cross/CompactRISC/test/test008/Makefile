all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o test.x
	cr16-elf-ld -o test.elf test.o -T test.x

test.lof:test.log
