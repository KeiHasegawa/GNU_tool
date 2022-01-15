all:test.objdump test.lof

include ../Makefile.common

start.o:/home/khasegawa/lang/53_GNU_tool/gcc_cross/FR-V/tool/start.S
	frv-elf-as -o $@ -g $<

test.elf:start.o test.o test.x
	frv-elf-ld -o $@ start.o test.o -T test.x

test.lof:test.log
