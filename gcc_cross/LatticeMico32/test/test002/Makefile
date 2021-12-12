all:test002.objdump test002.lof

include ../Makefile.common

#test002.s:test002.c
#	lm32-elf-gcc -o $@ $< -S

#test002.o:test002.s
#	lm32-elf-as -o $@ $< -g

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/lm32-elf/10.2.0/libgcc.a

test002.elf:start.o test002.o test002.x
	lm32-elf-ld -o $@ start.o test002.o $(LIBGCC) \
	-T test002.x -Map test002.map

test002.lof:test002.log
