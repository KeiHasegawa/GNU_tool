all:test010.objdump test010.lof

include ../Makefile.common

test010.elf:start.o test010.o test010.x

test010.log:test010.elf
	echo quit | wdog.exe -v mn10300-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test010.lof:test010.log
