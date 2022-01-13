all:test.objdump test.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/avr-elf/10.2.0/avr25/libgcc.a

test.elf:start.o test.o
	avr-elf-ld -o $@ start.o test.o -T ../default.x	$(LIBGCC)

test.lof:test.log
