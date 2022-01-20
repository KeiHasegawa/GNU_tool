all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	mcore-elf-ld -o test.elf test.o -T ../default.x

test.lof:test.log
