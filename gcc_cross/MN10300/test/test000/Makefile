all:test000.objdump test000.lof

include ../Makefile.common

test000.o.reloc:test000.o
	mn10300-elf-objdump -r $< > $@

test000.o.addr2line:test000.o
	mn10300-elf-addr2line -a 0x0 -e $< > $@
	mn10300-elf-addr2line -a 0x2 -e $< >> $@
	mn10300-elf-addr2line -a 0x4 -e $< >> $@
	mn10300-elf-addr2line -a 0x6 -e $< >> $@

test000.elf:test000.o test000.x
	mn10300-elf-ld -o test000.elf test000.o -T test000.x -Map test000.map

test000.addr2line:test000.elf
	mn10300-elf-addr2line -a 0x100 -e $< > $@
	mn10300-elf-addr2line -a 0x102 -e $< >> $@
	mn10300-elf-addr2line -a 0x104 -e $< >> $@
	mn10300-elf-addr2line -a 0x106 -e $< >> $@

test000.lof:test000.log
