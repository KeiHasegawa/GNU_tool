all:test020.objdump test020.lof

include ../Makefile.common

test020.elf:test020.o test020.x
	pru-elf-ld -o $@ $< -T test020.x

test020.log:test020.elf
	echo quit | wdog.exe -v pru-elf-gdb -q -x gdbcom $< > $@ 2>&1

test020.lof:test020.log
