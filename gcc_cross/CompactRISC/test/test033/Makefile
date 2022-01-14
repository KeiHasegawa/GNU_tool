all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../default.o Makefile
	cr16-elf-ld -o $@ ../default.o test.o -T ../default.x \
	-Map test.map --defsym _var=0xc

test.o.objdump:test.o
	cr16-elf-objdump -x -d --dwarf=rawline,decodedline $< > $@

test.objdump:test.elf
	cr16-elf-objdump -x -d --dwarf=rawline,decodedline $< > $@

test.objdump.2:test.elf
	cr16-elf-objdump -x -d -g $< > $@

test.lof:test.log

