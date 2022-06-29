all:test.objdump test.lof

include ../Makefile.common

test.s:test.c

test.o:test.s

test.elf:test.o ../default.o

test.objdump:test.elf

test.lof:test.log
