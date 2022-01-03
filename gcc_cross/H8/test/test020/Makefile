all:test020.objdump test020.lof

include ../Makefile.common

test020.elf:test020.o test020.x
	h8300-elf-ld -o $@ $< -T test020.x --defsym label=0xf0

test020.log:test020.elf gdbcom
	echo quit | wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test020.lof:test020.log
