all:test.objdump test.lof

include ../Makefile.common

test.elf:start.o test.o test_sub.o
	cr16-elf-ld -o $@ start.o test.o test_sub.o -T ../default.x

test.lof:test.log
