all:test009.objdump test009.lof

include ../Makefile.common

test009.elf:test009.o test009.x
	rx-elf-ld -o $@ $< -T $(basename $<).x

test009.log:test009.elf
	echo quit | wdog.exe -v rx-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test009.lof:test009.log
