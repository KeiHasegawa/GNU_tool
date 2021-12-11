all:test026.objdump test026.lof

include ../Makefile.common

test026.elf:start.o test026.o test026.x Makefile
	cr16-elf-ld -o $@ start.o test026.o -T test026.x -Map test026.map

test026.o.objdump:test026.o
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test026.objdump:test026.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test026.lof:test026.log
