all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../default.o test_sub.o
	rx-elf-ld -o $@ ../default.o $< test_sub.o -T ../default.x

test.lof:test.log
