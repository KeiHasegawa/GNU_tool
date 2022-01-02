all:test037.objdump test037.lof

include ../Makefile.common

test037.elf:test037.o test037.x
	cr16-elf-ld -o $@ $< -T test037.x --defsym label=0x200

test037.log:test037.elf gdbcom
	echo quit | wdog.exe -v cr16-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test037.lof:test037.log
