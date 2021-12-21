all:test010.objdump test010.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lm32-elf/lib

test010.elf:test010.o test010.x start.o
	lm32-elf-ld -o $@ start.o $< -T $(basename $<).x -L$(DIR) -lc

test010.lof:test010.log
