all:test024.objdump test024.lof

include ../Makefile.common

test024.elf:test024.o test024_sub1.o test024_sub2.o test024_sub3.o test024.x
	cr16-elf-ld -o $@ test024.o \
	test024_sub1.o test024_sub2.o test024_sub3.o \
	-T test024.x -Map test024.map \
	--defsym label=0x100000 --defsym label2=0x1000 --defsym label3=0x200 \
	--defsym back=0x106 --defsym back2=0x10c --defsym=back3=0x110

test024.elf:Makefile

test024.o.objdump:test024.o
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test024.objdump:test024.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test024.lof:test024.log
