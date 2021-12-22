all:test017.objdump test017.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/avr-elf/lib

test017.elf:test017.o test017.x start.o
	avr-elf-ld -o $@ start.o $< -T $(basename $<).x -L$(DIR) -lc

test017.lof:test017.log
