all:test003.objdump test003.lof

include ../Makefile.common

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/mips-elf/lib/libc.a

LIBIDT = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/mips-elf/lib/libidt.a

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/mips-elf/10.2.0/libgcc.a


test003.elf:start.o test003.o test003.x
	mips-elf-ld -o $@ start.o test003.o -T test003.x \
	$(LIBC) $(LIBIDT) $(LIBGCC)

test003.log:test003.elf
	wdog.exe -v mips-elf-gdb -q -x gdbcom $< > $@ 2>&1

test003.lof:test003.log
