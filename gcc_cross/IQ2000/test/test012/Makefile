all:test012.objdump test012.lof

include ../Makefile.common

test012.elf:start.o test012.o test012.x

test012.log:test012.elf gdbcom
	echo quit | wdog.exe -v iq2000-elf-gdb -q -x gdbcom $< > $@ 2>&1

test012.lof:test012.log

