all:test009.objdump test009.lof

include ../Makefile.common

test009.elf:start.o test009.o test009.x

test009.log:test009.elf gdbcom
	echo quit | wdog.exe -v cris-elf-gdb -q -x gdbcom $< > $@ 2>&1

test009.lof:test009.log
