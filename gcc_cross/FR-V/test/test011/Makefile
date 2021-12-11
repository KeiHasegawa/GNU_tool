all:test011.objdump test011.lof

include ../Makefile.common

start.o:/home/khasegawa/lang/53_GNU_tool/gcc_cross/FR-V/tool/start.S
	frv-elf-as -o $@ -g $<

test011.elf:start.o test011.o

test011.lof:test011.log
