all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o start.o
	wdog.exe -v msp430-elf-ld -o $@ start.o $< -T ../default.x

test.lof:test.log
