all:test.objdump test.lof

include ../Makefile.common

START_O = /home/khasegawa/lang/53_GNU_tool/gcc_cross/IQ2000/tool/start.o
LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/iq2000-elf/10.2.0/libgcc.a
SAMPLE_X = /home/khasegawa/lang/53_GNU_tool/gcc_cross/IQ2000/tool/sample.x

test.elf:test.o
	iq2000-elf-ld -o $@ $(START_O) test.o $(LIBGCC) -T $(SAMPLE_X)

test.lof:test.log
