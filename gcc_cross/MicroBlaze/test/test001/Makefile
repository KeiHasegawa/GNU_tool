all:start.objdump start.lof

include ../Makefile.common

start.elf:start.o
	microblaze-elf-ld -o $@ $< -T ../default.x

start.lof:start.log
