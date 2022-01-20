all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	mcore-elf-ld -o $@ $< -T ../default.x

test.log:test.elf
	echo quit | wdog.exe -v mcore-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test.lof:test.log
