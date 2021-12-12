all:test005.objdump test005.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m68hc11-elf/3.4.4/libgcc.a

test005.elf:start.o test005.o test005.x
	m68hc11-elf-ld -o test005.elf start.o test005.o \
	$(LIBC) $(LIBGCC) -T test005.x -Map test005.map

test005.lof:test005.log
