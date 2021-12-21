all:test011.objdump test011.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/rx-elf/lib

test011.elf:test011.o test011.x start.o
	rx-elf-ld -o $@ start.o $< -T $(basename $<).x -L$(DIR) -lc

test011.lof:test011.log
