all:test008.objdump test008.lof

include ../Makefile.common

test008.elf:start.o test008.o test008.x

test008.log:test008.elf gdbcom
	echo quit | wdog.exe -v bfin-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test008.lof:test008.log
