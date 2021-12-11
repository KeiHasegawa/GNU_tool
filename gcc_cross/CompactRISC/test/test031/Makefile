all:test031.objdump test031.lof

include ../Makefile.common

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/cr16-elf/lib/libc.a

test031.elf:start.o test031.o test031.x Makefile
	cr16-elf-ld -o $@ start.o test031.o -T test031.x \
	-Map test031.map $(LIBC)

test031.o.objdump:test031.o
	cr16-elf-objdump -x -d --dwarf=rawline,decodedline $< > $@

test031.objdump:test031.elf
	cr16-elf-objdump -x -d --dwarf=rawline,decodedline $< > $@

test031.objdump.2:test031.elf
	cr16-elf-objdump -x -d -g $< > $@

test031.lof:test031.log

