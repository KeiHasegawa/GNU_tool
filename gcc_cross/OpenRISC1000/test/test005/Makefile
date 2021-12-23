all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:hello.c
	or1k-elf-gcc -o $@ $< -g -Wl,-Map -Wl,hello.map

hello.log:hello.elf
	echo quit | wdog.exe -v or1k-elf-gdb -q -x gdbcom $< > $@

hello.lof:hello.log
