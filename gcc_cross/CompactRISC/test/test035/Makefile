all:test035.objdump test035.lof

include ../Makefile.common

test035.elf:start.o test035.o test035.x
	cr16-elf-ld -o $@ start.o test035.o -T test035.x

test035.objdump:test035.elf
	cr16-elf-objdump -x -d $< > $@

test035.lof:test035.log
