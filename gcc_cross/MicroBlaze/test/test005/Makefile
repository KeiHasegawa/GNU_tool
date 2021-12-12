all:hello.objdump hello.lof

include ../Makefile.common

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/microblaze-elf/10.2.0

hello.elf:start.o hello.o dummy.o
	microblaze-elf-ld -o hello.elf start.o hello.o dummy.o \
	-lc -L$(DIR) -lgcc -Map hello.map

hello.lof:hello.log
