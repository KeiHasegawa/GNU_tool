all:test022.objdump test022.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/aarch64-elf/lib

test022.elf:test022.o test022.x start.o
	aarch64-elf-ld -o $@ start.o $< -T $(basename $<).x -L$(DIR) -lc

test022.lof:test022.log
