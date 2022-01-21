all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	mn10300-elf-ld -o test.elf test.o -T ../default.x

test.lof:test.log

test.o.addr2line:test.o
	mn10300-elf-addr2line -a 0x0 -e $< > $@
	mn10300-elf-addr2line -a 0x1 -e $< >> $@
	mn10300-elf-addr2line -a 0x2 -e $< >> $@
	mn10300-elf-addr2line -a 0x3 -e $< >> $@

test.addr2line:test.elf
	mn10300-elf-addr2line -a 0x100 -e $< > $@
	mn10300-elf-addr2line -a 0x101 -e $< >> $@
	mn10300-elf-addr2line -a 0x102 -e $< >> $@
	mn10300-elf-addr2line -a 0x103 -e $< >> $@
