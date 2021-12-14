all:test019.objdump test019.lof

include ../Makefile.common

test019.elf:test019.o test019.x
	h8300-elf-ld -o $@ $< -T test019.x

test019.log:test019.elf gdbcom
	wdog.exe -v echo quit | h8300-elf-gdb -q -x gdbcom $< > $@ 2>&1

test019.lof:test019.log
