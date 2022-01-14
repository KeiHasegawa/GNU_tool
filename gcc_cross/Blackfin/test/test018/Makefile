all:start.objdump start.lof

include ../Makefile.common

start.elf:start.o
	bfin-elf-ld -o start.elf start.o -T ../default.x

start.log:start.elf gdbcom

start.lof:start.log
