all:test011.objdump test011.lof

include ../Makefile.common

test011.elf:test011.o test011.x
	msp430-elf-ld -o $@ $< -T test011.x

test011.log:test011.elf
	echo quit | wdog.exe -v msp430-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test011.lof:test011.log
