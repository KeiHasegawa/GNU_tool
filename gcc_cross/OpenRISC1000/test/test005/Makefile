all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:hello.c
	or1k-elf-gcc -o $@ $< -g -Wl,-Map -Wl,hello.map

hello.lof:hello.log
