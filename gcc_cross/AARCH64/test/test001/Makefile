all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:hello.o start.o dummy.o
	aarch64-elf-ld -o $@ start.o $< dummy.o -Map $(basename $<).map -lc

hello.lof:hello.log
