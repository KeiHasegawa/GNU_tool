all:test021.objdump test021.lof

include ../Makefile.common

test021.elf:test021.o test021.x Makefile
	cr16-elf-ld -o $@ test021.o \
	-T test021.x -Map test021.map --defsym label=0x1000

test021.objdump:test021.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test021.lof:test021.log
