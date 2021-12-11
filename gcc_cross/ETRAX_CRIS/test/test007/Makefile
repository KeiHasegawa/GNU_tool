all:test007.objdump test007.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/cris-elf/10.2.0/libgcc.a

test007.elf:start.o test007.o test007.x
	cris-elf-ld -o $@ start.o test007.o $(LIBGCC) \
	-T test007.x -Map test007.map

test007.objdump:test007.elf
	cris-elf-objdump -x -d -g $< > $@

test007.lof:test007.log
