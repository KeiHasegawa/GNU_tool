all:test015.objdump test015.lof

include ../Makefile.common

test015.elf:test015.o test015.x
	avr-elf-ld -o $@ $< -T test015.x

test015.log:test015.elf gdbcom
	echo quit | wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test015.lof:test015.log
