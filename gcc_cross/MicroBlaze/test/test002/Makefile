all:start.objdump start.lof

include ../Makefile.common

start.elf:start.o
	microblaze-elf-ld -o start.elf start.o -Map start.map

start.lof:start.log


