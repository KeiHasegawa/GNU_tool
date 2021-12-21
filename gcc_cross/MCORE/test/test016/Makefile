all:test016.objdump test016.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/mcore-elf/lib

test016.elf:test016.o test016.x start.o
	mcore-elf-ld -o $@ start.o $< -T $(basename $<).x -L$(DIR) -lc

test016.lof:test016.log
