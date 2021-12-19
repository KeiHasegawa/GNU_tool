all:test012.objdump test012.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/ft32-elf/lib

test012.elf:start.o test012.o test012.x
	ft32-elf-ld -o $@ start.o test012.o -T test012.x -L$(DIR) -lc

test012.lof:test012.log

