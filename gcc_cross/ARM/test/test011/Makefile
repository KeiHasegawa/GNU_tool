all:test011.objdump test011.lof

include ../Makefile.common

test011.elf:start.o test011.o test011.x

test011.log:test011.elf
	wdog.exe -v echo quit | arm-elf-gdb -q -x gdbcom $< > $@ 2>&1

test011.lof:test011.log
