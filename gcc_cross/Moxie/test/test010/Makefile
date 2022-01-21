all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	moxie-elf-ld -o $@ $< -T ../default.x

test.log:test.elf
	echo quit | wdog.exe -v moxie-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test.lof:test.log
