all:test.objdump test.lof

include ../Makefile.common

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/cr16-elf/lib/libc.a

test.elf:test.o ../default.o Makefile
	cr16-elf-ld -o $@ ../default.o test.o -T ../default.x \
	-Map test.map $(LIBC)

test.lof:test.log

