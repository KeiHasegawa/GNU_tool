all:start.objdump start.lof

include ../Makefile.common

start.elf:start.o
	microblaze-elf-ld -o start.elf start.o -T ../default.x

start.lof:start.log
