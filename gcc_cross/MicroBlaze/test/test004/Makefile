all:start.objdump start.lof

include ../Makefile.common

start.elf:start.o start.x
	microblaze-elf-ld -o start.elf start.o -T start.x -Map start.map

start.lof:start.log
