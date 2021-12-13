all:test011.objdump test011.lof

include ../Makefile.common

test011.elf:start.o test011.o test011_sub.o test011.x
	pru-elf-ld -o test011.elf start.o test011.o  test011_sub.o \
	-T test011.x -Map test011.map

test011.lof:test011.log
