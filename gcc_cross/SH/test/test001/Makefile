all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:hello.c
	sh-elf-gcc -o $@ $< -g

hello.log:hello.elf
	wdog.exe -v sh-elf-gdb -q -x gdbcom $< > $@ 2>&1

hello.lof:hello.log
