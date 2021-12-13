all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:hello.c
	moxie-elf-gcc -g -o $@ $< -T sim.ld

hello.lof:hello.log

