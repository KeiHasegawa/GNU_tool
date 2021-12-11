all:test015.objdump test015.lof

include ../Makefile.common

test015.a:test015a.o test015b.o test015c.o
	ar r $@ test015a.o test015b.o test015c.o

test015.elf:start.o test015.o test015.a test015.x
	cr16-elf-ld -o $@ start.o test015.o test015.a \
	-T test015.x --defsym _heap=0x1000

test015.lof:test015.log
