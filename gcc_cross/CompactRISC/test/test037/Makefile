all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	cr16-elf-ld -o $@ $< -T ../default.x --defsym label=0x200

test.log:test.elf gdbcom
	echo quit | wdog.exe -v cr16-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test.lof:test.log
