all:hello.objdump hello.lof

include ../Makefile.common

DIR1 = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/cris-elf/lib
DIR2 = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/cris-elf/10.2.0

hello.elf:start.o hello.o dummy.o hello.x
	cris-elf-ld -o hello.elf start.o hello.o dummy.o \
	-L$(DIR1) -lc -L$(DIR2) -lgcc -T hello.x -Map hello.map

hello.lof:hello.log

