all:test011.objdump test011.lof

include ../Makefile.common

test011.elf:start.o test011.o test011_sub.o test011.x
	cr16-elf-ld -o $@ start.o test011.o test011_sub.o \
	-T test011.x

test011.lof:test011.log
