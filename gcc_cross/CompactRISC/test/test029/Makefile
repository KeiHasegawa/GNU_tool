all:test029.objdump test029.lof

include ../Makefile.common

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/cr16-elf/lib/libc.a

test029.elf:start.o test029.o test029.x Makefile
	cr16-elf-ld -o $@ start.o test029.o -T test029.x \
	-Map test029.map $(LIBC)

test029.o.objdump:test029.o
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test029.objdump:test029.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test029.lof:test029.log

