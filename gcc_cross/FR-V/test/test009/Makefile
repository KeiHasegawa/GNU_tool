all:test009.objdump test009.lof

include ../Makefile.common

test009.elf:start.o test009.o
	frv-elf-ld -o $@ start.o test009.o -Map test009.map -lc -lsim \
	-L/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/frv-elf/lib

test009.lof:test009.log
