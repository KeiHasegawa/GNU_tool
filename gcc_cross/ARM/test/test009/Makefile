all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../default.o

test.log:test.elf
	echo quit | wdog.exe -v arm-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test.lof:test.log
