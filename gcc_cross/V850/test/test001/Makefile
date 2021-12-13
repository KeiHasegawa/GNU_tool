all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:hello.c
	v850-elf-gcc -g -o $@ $<

hello.log:hello.elf
	v850-elf-gdb -q -x gdbcom $< > $@ 2>&1

hello.lof:hello.log
