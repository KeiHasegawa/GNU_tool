all:test023.objdump test023.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/h8300-elf/lib

test023.elf:test023.o test023.x start.o
	h8300-elf-ld -o $@ start.o $< -T $(basename $<).x -L$(DIR) -lc

test023.lof:test023.log
