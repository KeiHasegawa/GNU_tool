all:test013.objdump test013.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/moxie-elf/lib

test013.elf:test013.o test013.x start.o
	moxie-elf-ld -o $@ start.o $< -T $(basename $<).x -L$(DIR) -lc

test013.lof:test013.log
