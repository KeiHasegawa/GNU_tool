all:start.elf start.lof

include ../Makefile.common

start.elf:start.o
	frv-elf-ld -o $@ $< -T start.x -Map start.map

start.elf:Makefile
start.elf:start.x

start.lof:start.log
