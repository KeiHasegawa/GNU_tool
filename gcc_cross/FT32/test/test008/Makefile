all:test008.objdump test008.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/ft32-elf/10.2.0/libgcc.a

test008.elf:start.o test008.o test008.x
	ft32-elf-ld -o $@ start.o test008.o \
	$(LIBGCC) -T test008.x -Map test008.map

test008.lof:test008.log


