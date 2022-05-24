all:test.objdump test.lof

include ../Makefile.common

test.o:test.S

test.coff:test.o
	alpha-coff-ld -o $@ $< -T ../default.x

test.objdump:test.coff

test.lof:test.log
