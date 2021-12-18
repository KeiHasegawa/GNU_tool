all:test012.objdump test012.lof

include ../Makefile.common

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/m68hc11-elf/lib/libc.a

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m68hc11-elf/3.4.4/libgcc.a

test012.elf:start.o test012.o dummy.o test012.x
	m68hc11-elf-ld -o test012.elf start.o test012.o dummy.o \
	$(LIBC) $(LIBGCC) -T test012.x -Map test012.map

test012.log:test012.elf
	wdog.exe -v echo quit | m68hc11-elf-gdb -q -x gdbcom $< > $@ 2>&1
