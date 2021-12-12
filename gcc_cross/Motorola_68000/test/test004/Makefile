all:hello.objdump hello.lof

include ../Makefile.common

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/m68hc11-elf/lib/libc.a

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m68hc11-elf/3.4.4/libgcc.a

hello.elf:start.o hello.o dummy.o hello.x
	m68hc11-elf-ld -o hello.elf start.o hello.o dummy.o \
	$(LIBC) $(LIBGCC) -T hello.x -Map hello.map

hello.lof:hello.log
