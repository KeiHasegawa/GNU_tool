all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	rl78-elf-ld -o $@ $< -T ../default.x

test.log:test.elf
	echo quit | wdog.exe -v rl78-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test.lof:test.log
