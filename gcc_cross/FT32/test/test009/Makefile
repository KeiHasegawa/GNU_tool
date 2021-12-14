all:test009.objdump test009.lof

include ../Makefile.common

test009.elf:test009.o test009.x
	ft32-elf-ld -o $@ $< -T test009.x 

test009.log:test009.elf gdbcom
	wdog.exe -v echo quit | ft32-elf-gdb -q -x gdbcom $< > $@ 2>&1

test009.lof:test009.log
