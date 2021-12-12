all:test003.objdump test003.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m32c-elf/10.2.0/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/m32c-elf/lib/libc.a

test003.elf:start.o test003.o test003.x
	m32c-elf-ld -o test003.elf start.o  test003.o  \
	$(LIBGCC) $(LIBC) -T test003.x -Map test003.map

test003.lof:test003.log
