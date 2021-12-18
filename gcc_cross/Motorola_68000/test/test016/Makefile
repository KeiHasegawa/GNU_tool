all:test016.objdump test016.lof

include ../Makefile.common

test016.elf:test016.o
	m68hc11-elf-ld -o $@ $< -T test016.x

test016.log:test016.elf
	echo quit | wdog.exe -v m68hc11-elf-gdb -q -x gdbcom $< > $@ 2>&1

test016.lof:test016.log
