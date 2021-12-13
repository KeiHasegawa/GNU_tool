all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:hello.c
	mn10300-elf-gcc -o $@ -g $< -Tsim.ld

hello.log:hello.elf
	wdog.exe -v mn10300-elf-gdb -q -x gdbcom $< > $@ 2>&1

hello.lof:hello.log
