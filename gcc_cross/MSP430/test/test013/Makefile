all:test.objdump test.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/msp430-elf/lib

test.elf:test.o
	wdog.exe -v msp430-elf-ld -o $@ ../default.o $< -T ../default.x -L$(DIR) -lc

test.lof:test.log
