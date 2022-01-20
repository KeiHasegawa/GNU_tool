all:test.objdump test.lof

include ../Makefile.common

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/mips-elf/lib/libc.a

LIBIDT = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/mips-elf/lib/libidt.a

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/mips-elf/10.2.0/libgcc.a


test.elf:start.o test.o test.x
	mips-elf-ld -o $@ start.o test.o -T test.x \
	$(LIBC) $(LIBIDT) $(LIBGCC)

test.log:test.elf
	wdog.exe -v mips-elf-gdb -q -x gdbcom $< > $@ 2>&1

test.lof:test.log
