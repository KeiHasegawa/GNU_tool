all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o Makefile
	cr16-elf-ld -o $@ test.o -T ../default.x -Map test.map \
	--defsym label=0x100000 --defsym label2=0x1000 --defsym label3=0x100

test.o.objdump:test.o
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test.objdump:test.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test.lof:test.log
