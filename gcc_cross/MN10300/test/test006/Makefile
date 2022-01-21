all:test.objdump test.lof

include ../Makefile.common

test.o.reloc:test.o
	mn10300-elf-objdump -r $< > $@

test.o.addr2line:test.o
	mn10300-elf-addr2line -a 0x0 -e $< > $@
	mn10300-elf-addr2line -a 0x2 -e $< >> $@
	mn10300-elf-addr2line -a 0x4 -e $< >> $@
	mn10300-elf-addr2line -a 0x6 -e $< >> $@

test.elf:test.o
	mn10300-elf-ld -o test.elf test.o -T ../default.x

test.addr2line:test.elf
	mn10300-elf-addr2line -a 0x100 -e $< > $@
	mn10300-elf-addr2line -a 0x102 -e $< >> $@
	mn10300-elf-addr2line -a 0x104 -e $< >> $@
	mn10300-elf-addr2line -a 0x106 -e $< >> $@

test.lof:test.log
