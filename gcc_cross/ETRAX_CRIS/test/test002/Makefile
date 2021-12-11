all:test002.objdump test002.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/cris-elf/10.2.0/libgcc.a

test002.elf:start.o test002.o test002.x
	cris-elf-ld -o $@ start.o test002.o $(LIBGCC) \
	-T test002.x -Map test002.map

test002.objdump:test002.elf
	cris-elf-objdump -x -d -g $< > $@

test002.lof:test002.log

