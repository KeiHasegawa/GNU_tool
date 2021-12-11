all:test020.objdump test020.lof

include ../Makefile.common

test020.elf:test020.o test020.x Makefile
	cr16-elf-ld -o $@ test020.o \
	-T test020.x -Map test020.map --defsym label=0x100

test020.objdump:test020.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test020.lof:test020.log
