all:test010.objdump test010.lof

include ../Makefile.common

test010.elf:test010.o test010.x
	msp430-elf-ld -o $@ $< -T test010.x

test010.log:test010.elf
	echo quit | wdog.exe -v msp430-elf-gdb -q -x gdbcom $< > $@ 2>&1

test010.lof:test010.log
