all:test006.objdump test006.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m68hc11-elf/3.4.4/libgcc.a

test006.elf:start.o test006.o test006.x
	m68hc11-elf-ld -o test006.elf start.o test006.o \
	$(LIBC) $(LIBGCC) -T test006.x -Map test006.map

test006.lof:test006.log
