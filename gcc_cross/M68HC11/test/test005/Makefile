all:test.objdump test.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m68hc11-elf/3.4.4/libgcc.a

test.elf:test.o ../default.o
	m68hc11-elf-ld -o test.elf ../default.o test.o \
	$(LIBC) $(LIBGCC) -T ../default.x -Map test.map

test.lof:test.log
