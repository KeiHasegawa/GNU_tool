all:test015.objdump test015.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/frv-elf/lib

test015.elf:test015.o test015.x start.o
	frv-elf-ld -o $@ start.o $< -T $(basename $<).x -L$(DIR) -lc

test015.lof:test015.log
