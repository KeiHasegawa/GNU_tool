all:test009.objdump test009.lof

include ../Makefile.common

test009.elf:test009.o test009.x
	m32r-elf-ld -o $@ $< -T test009.x

test009.log:test009.elf
	echo quit | wdog.exe -v m32r-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test009.lof:test009.log
