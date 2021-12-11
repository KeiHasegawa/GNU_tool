all:test022.objdump test022.lof

include ../Makefile.common

test022.elf:test022.o test022.x Makefile
	cr16-elf-ld -o $@ test022.o -T test022.x -Map test022.map \
	--defsym label=0x100000 --defsym label2=0x1000 --defsym label3=0x100

test022.o.objdump:test022.o
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test022.objdump:test022.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test022.lof:test022.log
