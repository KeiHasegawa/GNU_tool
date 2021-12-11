all:hello.objdump hello.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/frv-elf/10.2.0/libgcc.a
LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/frv-elf/lib/libc.a

hello.elf:start.o hello.o dummy.o hello.x
	frv-elf-ld -o $@ start.o hello.o dummy.o $(LIBGCC) $(LIBC) -T hello.x

hello.lof:hello.log
