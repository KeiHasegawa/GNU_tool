all:test030.objdump test030.lof

include ../Makefile.common

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/cr16-elf/lib/libc.a

test030.elf:start.o test030.o test030.x Makefile
	cr16-elf-ld -o $@ start.o test030.o -T test030.x \
	-Map test030.map $(LIBC)

test030.o.objdump:test030.o
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test030.objdump:test030.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test030.lof:test030.log


