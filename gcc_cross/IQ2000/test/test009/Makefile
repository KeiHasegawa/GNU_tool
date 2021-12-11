all:test009.objdump test009.lof

include ../Makefile.common

start.o:/home/khasegawa/lang/53_GNU_tool/gcc_cross/IQ2000/tool/start.S
	iq2000-elf-as -o $@ -g $<

test009.elf:start.o test009.o
	iq2000-elf-ld -o $@ start.o test009.o \
/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/iq2000-elf/10.2.0/libgcc.a \
-T /home/khasegawa/lang/53_GNU_tool/gcc_cross/IQ2000/tool/sample.x

test009.lof:test009.log
