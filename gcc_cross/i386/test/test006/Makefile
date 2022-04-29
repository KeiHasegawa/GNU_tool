all:test.objdump test.lof

include ../Makefile.common

por.o:por.S

gdt.o:gdt.S

startup.o:startup.S

test.o:test.c

test.elf:por.o gdt.o startup.o test.o test.x
	i386-elf-ld -o $@ -T test.x

test.objdump:test.elf
	i386-elf-objdump -x -d -g -M data16 -M addr16 $< > $@

test.lof:test.log
