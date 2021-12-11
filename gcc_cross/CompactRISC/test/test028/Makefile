all:test028.objdump test028.lof

include ../Makefile.common

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/cr16-elf/lib/libc.a

test028.elf:start.o test028.o test028.x Makefile
	cr16-elf-ld -o $@ start.o test028.o -T test028.x \
	-Map test028.map $(LIBC)

test028.o.objdump:test028.o
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test028.objdump:test028.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test028.lof:test028.log

