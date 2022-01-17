all:test.objdump test.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/lm32-elf/10.2.0/libgcc.a

test.elf:start.o test.o
	lm32-elf-ld -o $@ start.o test.o $(LIBGCC) -T ../default.x

test.lof:test.log
