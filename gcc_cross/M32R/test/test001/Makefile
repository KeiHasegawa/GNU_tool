all:hello.objdump hello.lof

include ../Makefile.common

PREFIX = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG

hello.elf:hello.c
	m32r-elf-gcc -g -o hello.elf hello.c

hello.log:hello.elf
	echo quit | wdog.exe -v m32r-elf-gdb -q -x gdbcom $< > $@ 2>&1

hello.lof:hello.log
