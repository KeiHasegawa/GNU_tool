all:hello.objdump hello.lof

include ../Makefile.common

DIR0 = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG
DIR1 = $(DIR0)/bfin-elf/lib
DIR2 = $(DIR0)/lib/gcc/bfin-elf/10.2.0

hello.elf:start.o hello.o dummy.o hello.x
	bfin-elf-ld -o hello.elf start.o hello.o dummy.o \
	-L$(DIR1) -lc -L$(DIR2) -lgcc \
	-T hello.x

hello.lof:hello.log
