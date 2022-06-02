all:test.objdump test.lof

include ../Makefile.common

test.s:test.c
	ns32k-elf-gcc -S $<

test.o:test.s
	ns32k-elf-as -o $@ $< -g

START_O = /home/khasegawa/lang/53_GNU_tool/gcc_cross/NS32000/tool/start.o
SAMPLE_X = /home/khasegawa/lang/53_GNU_tool/gcc_cross/NS32000/tool/sample.x

test.elf:test.o $(START_O)
	ns32k-elf-ld -o $@  $(START_O) $< -T $(SAMPLE_X)

test.lof:test.log

