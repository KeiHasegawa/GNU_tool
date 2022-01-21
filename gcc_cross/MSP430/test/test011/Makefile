all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	msp430-elf-ld -o $@ $< -T ../default.x

test.log:test.elf
	echo quit | wdog.exe -v msp430-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test.lof:test.log
