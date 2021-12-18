all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:hello.c
	iq2000-elf-gcc -o hello.elf -g hello.c -Wl,-Map -Wl,hello.map

hello.log:hello.elf
	wdog.exe -v iq2000-elf-gdb -q -x gdbcom $< > $@ 2>&1

hello.lof:hello.log
