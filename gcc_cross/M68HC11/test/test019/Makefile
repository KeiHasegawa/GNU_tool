all:test.objdump test.lof

include ../Makefile.common

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/m68hc11-elf/lib/libc.a

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m68hc11-elf/3.4.4/libgcc.a

test.elf:test.o start.o
	wdog.exe -v m68hc11-elf-ld -o $@ start.o $< $(LIBC) $(LIBGCC) \
	-T ../default.x

test.lof:test.log
