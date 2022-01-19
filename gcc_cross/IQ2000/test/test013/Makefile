all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	iq2000-elf-ld -o $@ $< -T ../default.x

test.log:test.elf gdbcom
	echo quit | wdog.exe -v iq2000-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL
test.lof:test.log

