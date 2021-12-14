all:test019.objdump test019.lof

include ../Makefile.common

test019.elf:start.o test019.o test019.x

test019.log:test019.elf
	wdog.exe -v echo quit | pru-elf-gdb -q -x gdbcom $< > $@ 2>&1

test019.lof:test019.log
