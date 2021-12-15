all:test012.objdump test012.lof

include ../Makefile.common

test012.elf:test012.o test012.x
	microblaze-elf-ld -o $@ $< -T test012.x

test012.log:test012.elf
	echo quit | wdog.exe -v microblaze-elf-gdb -q -x gdbcom $< > $@ 2>&1

test012.lof:test012.log
