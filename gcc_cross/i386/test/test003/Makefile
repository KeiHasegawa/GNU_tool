all:test.objdump test.lof

include ../Makefile.common

por.o:por.S

test.o:test.c

test.elf:por.o ../default.o test.o test.x
	i386-elf-ld -o $@ -T test.x

test.objdump:test.elf

test.lof:test.log
