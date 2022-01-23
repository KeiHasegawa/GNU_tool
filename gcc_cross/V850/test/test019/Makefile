all:test.lof

include ../Makefile.common

test.elf:test.o
	v850-elf-ld -o $@ $< -T ../default.x

test.log:test.elf
	v850-elf-objdump -d $< > $@

test.lof:test.log
	wdog.exe -v diff $< $@
	touch $@
