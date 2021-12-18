all:test008.objdump test008.lof

include ../Makefile.common

test008.elf:test008.o test008.x
	rx-elf-ld -o $@ $< -T $(basename $<).x

test008.log:test008.elf
	echo quit | wdog.exe -v rx-elf-gdb -q -x gdbcom $< > $@ 2>&1

test008.lof:test008.log
