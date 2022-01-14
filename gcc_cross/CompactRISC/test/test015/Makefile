all:test.objdump test.lof

include ../Makefile.common

test.a:testa.o testb.o testc.o
	ar r $@ testa.o testb.o testc.o

test.elf:test.o test.a ../default.o
	cr16-elf-ld -o $@ ../default.o test.o test.a \
	-T ../default.x --defsym _heap=0x1000

test.lof:test.log
