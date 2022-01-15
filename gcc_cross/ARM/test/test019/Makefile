all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../default.o subr.o
	arm-elf-ld -o test.elf ../default.o test.o subr.o -T ../default.x

test.lof:test.log
