all:hello.objdump hello.lof

include ../Makefile.common

DIR1 = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/cr16-elf/lib
DIR2 = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/cr16-elf/10.2.0

hello.elf:start.o hello.o dummy.o hello.x
	cr16-elf-ld -o hello.elf start.o hello.o dummy.o \
	-L$(DIR1) -lc -L$(DIR2) -lgcc -T hello.x

hello.lof:hello.log
