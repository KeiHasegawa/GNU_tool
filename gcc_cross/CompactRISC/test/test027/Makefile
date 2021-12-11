all:test027.objdump test027.lof

include ../Makefile.common

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/cr16-elf/lib/libc.a

test027.elf:start.o test027.o test027.x Makefile
	cr16-elf-ld -o $@ start.o test027.o -T test027.x \
	-Map test027.map $(LIBC)

test027.lof:test027.log

