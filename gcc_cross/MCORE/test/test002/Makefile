all:hello.objdump hello.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/mcore-elf/lib

hello.elf:start.o hello.o dummy.o hello.x
	mcore-elf-ld -o hello.elf start.o hello.o dummy.o \
	-T hello.x -Map hello.map -L$(DIR) -lc

hello.lof:hello.log

