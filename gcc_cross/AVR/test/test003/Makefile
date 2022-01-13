all:test.objdump test.lof

include ../Makefile.common

test.elf:start.o test.o test003.x
	avr-elf-ld -o $@ start.o test.o -Map start.map -T test003.x

test.lof:test.log
