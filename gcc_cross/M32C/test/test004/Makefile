all:test.objdump test.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m32c-elf/10.2.0/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/m32c-elf/lib/libc.a

test.elf:test.o ../default.o
	m32c-elf-ld -o $@ ../default.o $< $(LIBGCC) $(LIBC) -T ../default.x

test.lof:test.log
