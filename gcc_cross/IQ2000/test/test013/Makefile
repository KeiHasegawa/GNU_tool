all:test013.objdump test013.lof

include ../Makefile.common

test013.elf:test013.o test013.x
	iq2000-elf-ld -o $@ $< -T test013.x

test013.log:test013.elf gdbcom
	echo quit | wdog.exe -v iq2000-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL
test013.lof:test013.log

