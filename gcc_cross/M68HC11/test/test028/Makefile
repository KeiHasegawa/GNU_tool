all:test.objdump test.lof

include ../Makefile.common

DIR = /home/khasegawa/lang/53_GNU_tool/gcc_cross/M68HC11/tool
START_O = $(DIR)/start.o
SAMPLE_X = $(DIR)/sample.x
LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m68hc11-elf/4.2.0/libgcc.a

test.elf:test.o
	m68hc11-elf-ld -o test.elf $(START_O) test.o $(LIBGCC) -T $(SAMPLE_X)

test.lof:test.log
