all:test005.objdump test005.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m32c-elf/10.2.0/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/m32c-elf/lib/libc.a

test005.elf:start.o test005.o test005.x
	m32c-elf-ld -o test005.elf start.o  test005.o  \
	$(LIBGCC) $(LIBC) -T test005.x -Map test005.map

test005.lof:test005.log
