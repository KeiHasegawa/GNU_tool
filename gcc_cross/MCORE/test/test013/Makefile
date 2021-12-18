all:test013.objdump test013.lof

include ../Makefile.common

test013.elf:start.o test013.o test013.x

test013.log:test013.elf
	echo quit | wdog.exe -v mcore-elf-gdb -q -x gdbcom $< > $@ 2>&1

test013.lof:test013.log
