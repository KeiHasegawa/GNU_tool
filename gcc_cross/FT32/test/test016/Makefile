all:test016.objdump test016.lof

include ../Makefile.common

DIR = /home/khasegawa/lang/53_GNU_tool/gcc_cross/FT32/tool/
START_O = $(DIR)/start.o
SAMPLE_X = $(DIR)/sample.x
LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/ft32-elf/10.2.0/libgcc.a

test016.s:test016.c
	ft32-elf-gcc -o $@ $< -S

test016.o:test016.s
	ft32-elf-as -o $@ $< -g --no-relax

test016.elf:test016.o
	ft32-elf-ld -o $@ $(START_O) $< $(LIBGCC) -T $(SAMPLE_X)

test016.lof:test016.log
