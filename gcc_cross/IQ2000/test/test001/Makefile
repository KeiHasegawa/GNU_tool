all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:hello.c
	iq2000-elf-gcc -o hello.elf -g hello.c -Wl,-Map -Wl,hello.map

hello.lof:hello.log
