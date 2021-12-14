all:test008.objdump test008.lof

include ../Makefile.common

test008.elf:start.o test008.o test008.x

test008.log:test008.elf
	wdog.exe -v echo quit | v850-elf-gdb -q -x gdbcom $< > $@ 2>&1

test008.lof:test008.log
