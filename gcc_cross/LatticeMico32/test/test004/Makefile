all:test004.objdump test004.lof

include ../Makefile.common

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/lm32-elf/10.2.0/libgcc.a

test004.elf:start.o test004.o test004.x
	lm32-elf-ld -o $@ start.o test004.o $(LIBGCC) \
	-T test004.x -Map test004.map

test004.lof:test004.log
