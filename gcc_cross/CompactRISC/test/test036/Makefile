all:test036.objdump test036.lof

include ../Makefile.common

test036.elf:start.o test036.o test036.x

test036.log:test036.elf gdbcom
	wdog.exe -v echo quit | cr16-elf-gdb -q -x gdbcom $< > $@ 2>&1

test036.lof:test036.log
