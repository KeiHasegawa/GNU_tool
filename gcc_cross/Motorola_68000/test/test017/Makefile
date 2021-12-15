all:test017.objdump test017.lof

include ../Makefile.common

test017.elf:test017.o
	m68hc11-elf-ld -o $@ $< -T test017.x

test017.log:test017.elf
	echo quit | wdog.exe -v m68hc11-elf-gdb -q -x gdbcom $< > $@ 2>&1

test017.lof:test017.log
