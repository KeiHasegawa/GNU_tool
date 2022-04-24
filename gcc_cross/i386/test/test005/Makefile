all:test.objdump test.lof

include ../Makefile.common

test.o:test.S

test.elf:test.o ../power_on_reset.o
	i386-elf-ld -o $@ $< -T ../use_por.x

test.objdump:test.elf

test.lof:test.log
