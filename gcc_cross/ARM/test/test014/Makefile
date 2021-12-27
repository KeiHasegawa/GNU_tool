all:test.objdump test.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/arm-elf/lib

test.elf:test.o test.x start.o
	arm-elf-ld -o $@ start.o $< -T $(basename $<).x -L$(DIR) -lc

test.lof:test.log
