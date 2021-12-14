all:test010.objdump test010.lof

include ../Makefile.common

test010.elf:test010.o test010.x
	moxie-elf-ld -o $@ $< -T test010.x

test010.log:test010.elf
	wdog.exe -v echo quit | moxie-elf-gdb -q -x gdbcom $< > $@ 2>&1

test010.lof:test010.log
