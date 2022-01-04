all:test019.objdump test019.lof

include ../Makefile.common

test019.elf:start.o test019.o test019.x

test019.log:test019.elf
	echo quit | wdog.exe -v aarch64-elf-gdb -x gdbcom $< > $@ 2>&1 || echo FAIL

test019.lof:test019.log
