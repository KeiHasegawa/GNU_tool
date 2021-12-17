all:hello.objdump hello.lof TAGS

include ../Makefile.common

hello.elf:hello.c
	arm-elf-gcc -o hello.elf -g hello.c

TAGS:hello.elf
	mktags.exe -e hello.elf

hello.lof:hello.log
