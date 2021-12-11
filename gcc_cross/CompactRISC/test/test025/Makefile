all:test025.objdump test025.lof

include ../Makefile.common

test025.elf:test025.o test025.x Makefile
	cr16-elf-ld -o $@ test025.o -T test025.x -Map test025.map \
	--defsym label1=0xf \
	--defsym label2=0x10 \
	--defsym label3=0xfff \
	--defsym label4=0x1000 \
	--defsym label5=0xfffff \
	--defsym label6=0x100000 \
	--defsym label10=0x252 \
	--defsym label11=0x258 \
	--defsym label12=0x100000 \



test025.o.objdump:test025.o
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test025.objdump:test025.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test025.lof:test025.log
