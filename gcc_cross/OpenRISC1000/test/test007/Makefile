all:test007.objdump test007.lof

include ../Makefile.common

test007.elf:start.o test007.o test007.x

test007.log:test007.elf
	wdog.exe -v echo quit | or1k-elf-gdb -q -x gdbcom $< > $@ 2>&1

test007.lof:test007.log
