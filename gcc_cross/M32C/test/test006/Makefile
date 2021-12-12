all:test006.objdump test006.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m32c-elf/10.2.0/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/m32c-elf/lib/libc.a

test006.elf:start.o test006.o test006.x
	m32c-elf-ld -o test006.elf start.o  test006.o  \
	$(LIBGCC) $(LIBC) -T test006.x -Map test006.map

test006.lof:test006.log
