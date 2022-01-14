all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o Makefile
	cr16-elf-ld -o $@ test.o \
	-T ../default.x -Map test.map --defsym label=0x100

test.objdump:test.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test.lof:test.log
