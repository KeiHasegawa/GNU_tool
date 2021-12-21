all:test039.objdump test039.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/cr16-elf/lib

test039.elf:test039.o test039.x start.o
	cr16-elf-ld -o $@ start.o $< -T $(basename $<).x -L$(DIR) -lc

test039.lof:test039.log
