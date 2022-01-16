all:test.objdump test.lof

include ../Makefile.common

DIR = /home/khasegawa/lang/53_GNU_tool/gcc_cross/FT32/tool/
START_O = $(DIR)/start.o
SAMPLE_X = $(DIR)/sample.x
LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/ft32-elf/10.2.0/libgcc.a

test.elf:test.o
	ft32-elf-ld -o $@ $(START_O) $< $(LIBGCC) -T $(SAMPLE_X)

test.lof:test.log
