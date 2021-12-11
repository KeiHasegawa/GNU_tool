all:test019.objdump test019.lof

include ../Makefile.common

test019.elf:test019.o test019.x Makefile
	cr16-elf-ld -o $@ test019.o \
	-T test019.x -Map test019.map --defsym label=0x100

test019.objdump:test019.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test019.lof:test019.log
