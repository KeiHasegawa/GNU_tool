all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:hello.c
	arm-elf-gcc -o hello.elf -g hello.c

TAGS:hello.elf
	mktags.exe -e hello.elf

hello.lof:hello.log
