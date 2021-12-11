all:test006.objdump test006.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/cris-elf/10.2.0/libgcc.a

test006.elf:start.o test006.o test006.x
	cris-elf-ld -o $@ start.o test006.o $(LIBGCC) \
	-T test006.x -Map test006.map

test006.objdump:test006.elf
	cris-elf-objdump -x -d -g $< > $@

test0006.lof:test006.log


