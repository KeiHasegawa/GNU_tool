all:test.objdump test.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/or1k-elf/lib

test.elf:test.o ../default.o
	or1k-elf-ld -o $@ ../default.o $< -L$(DIR) -lc -T ../default.x

test.lof:test.log
