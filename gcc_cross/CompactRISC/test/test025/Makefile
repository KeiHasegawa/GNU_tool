all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o Makefile
	cr16-elf-ld -o $@ test.o -T ../default.x -Map test.map \
	--defsym label1=0xf \
	--defsym label2=0x10 \
	--defsym label3=0xfff \
	--defsym label4=0x1000 \
	--defsym label5=0xfffff \
	--defsym label6=0x100000 \
	--defsym label10=0x252 \
	--defsym label11=0x258 \
	--defsym label12=0x100000 \



test.o.objdump:test.o
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test.objdump:test.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test.lof:test.log
