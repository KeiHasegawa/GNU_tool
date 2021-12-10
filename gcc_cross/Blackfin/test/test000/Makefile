all:start.objdump start.lof

include ../Makefile.common

start.elf:start.o start.x
	bfin-elf-ld -o start.elf start.o -T start.x

start.objdump:start.elf
	bfin-elf-objdump -x -d start.elf >  start.objdump

start.log:start.elf gdbcom

start.lof:start.log
