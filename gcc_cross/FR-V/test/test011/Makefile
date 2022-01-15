all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	frv-elf-ld -o $@ $< -T ../default.x

test.log:test.elf gdbcom
	echo quit | wdog.exe -v frv-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test.lof:test.log
