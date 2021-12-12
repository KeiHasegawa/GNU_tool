all:test007.objdump test007.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m32c-elf/10.2.0/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/m32c-elf/lib/libc.a

test007.elf:start.o test007.o test007.x
	m32c-elf-ld -o test007.elf start.o  test007.o  \
	$(LIBGCC) $(LIBC) -T test007.x -Map test007.map

test007.lof:test007.log
