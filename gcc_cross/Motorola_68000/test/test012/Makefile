all:test.objdump test.lof

include ../Makefile.common

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/m68hc11-elf/lib/libc.a

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m68hc11-elf/3.4.4/libgcc.a

test.elf:start.o test.o dummy.o test.x
	m68hc11-elf-ld -o test.elf start.o test.o dummy.o \
	$(LIBC) $(LIBGCC) -T test.x -Map test.map

test.log:test.elf
	wdog.exe -v echo quit | m68hc11-elf-gdb -q -x gdbcom $< > $@ 2>&1
