all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o test.x
	arm-elf-ld -o $@ $< -T $(basename $<).x

test.log:test.elf
	echo quit | wdog.exe -v arm-elf-gdb -q -x gdbcom $< > $@ 2>&1

test.lof:test.log
