all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../default.x

test.log:test.elf
	echo quit | wdog.exe -v aarch64-elf-gdb -x gdbcom $< > $@ 2>&1 || echo FAIL

test.lof:test.log
