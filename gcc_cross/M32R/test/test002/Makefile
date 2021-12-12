all:test002.objdump test002.lof

include ../Makefile.common

LIBGCC =/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m32r-elf/10.2.0/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/m32r-elf/lib/libc.a

test002.elf:start.o test002.o test002.x
	m32r-elf-ld -o $@ start.o test002.o \
	$(LIBGCC) $(LIBC) -T test002.x -Map test002.map

test002.lof:test002.log
