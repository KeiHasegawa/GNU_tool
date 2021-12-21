all:test014.objdump test014.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/microblaze-elf/lib

test014.elf:test014.o test014.x start.o
	microblaze-elf-ld -o $@ start.o $< -T $(basename $<).x -L$(DIR) -lc

test014.lof:test014.log
