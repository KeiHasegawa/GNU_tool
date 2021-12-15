all:test010.objdump test010.lof

include ../Makefile.common

test010.elf:test010.o test010.x
	cris-elf-ld -o $@ $< -T test010.x

test010.log:test010.elf gdbcom
	echo quit | wdog.exe -v cris-elf-gdb -q -x gdbcom $< > $@ 2>&1

test010.lof:test010.log
