all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o test.x
	or1k-elf-ld -o $@ $< -T $(basename $<).x

test.log:test.elf
	echo quit | wdog.exe -v or1k-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test.lof:test.log
