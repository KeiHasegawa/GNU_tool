all:test012.objdump test012.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/sh-elf/lib

test012.elf:test012.o test012.x start.o
	sh-elf-ld -o $@ start.o $< -T $(basename $<).x -L$(DIR) -lc

test012.lof:test012.log
