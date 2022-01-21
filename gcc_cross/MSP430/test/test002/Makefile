all:start.objdump start.lof

include ../Makefile.common

start.elf:start.o
	msp430-elf-ld -o start.elf start.o -T ../default.x

start.lof:start.log
