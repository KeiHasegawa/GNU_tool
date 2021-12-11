all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:start.o hello.o
	frv-elf-ld -o $@ start.o hello.o -Map hello.map -lc -lsim \
	-L/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/frv-elf/lib

hello.lof:hello.log


