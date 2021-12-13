all:test003.objdump test003.lof

include ../Makefile.common

test003.elf:test003.o test003.x
	mn10300-elf-ld -o test003.elf test003.o -T test003.x -Map test003.map

test003.lof:test003.log

test003.o.addr2line:test003.o
	mn10300-elf-addr2line -a 0x0 -e $< > $@
	mn10300-elf-addr2line -a 0x1 -e $< >> $@
	mn10300-elf-addr2line -a 0x2 -e $< >> $@
	mn10300-elf-addr2line -a 0x3 -e $< >> $@

test003.addr2line:test003.elf
	mn10300-elf-addr2line -a 0x100 -e $< > $@
	mn10300-elf-addr2line -a 0x101 -e $< >> $@
	mn10300-elf-addr2line -a 0x102 -e $< >> $@
	mn10300-elf-addr2line -a 0x103 -e $< >> $@
