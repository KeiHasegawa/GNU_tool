all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o test_sub1.o test_sub2.o test_sub3.o test.x
	cr16-elf-ld -o $@ test.o \
	test_sub1.o test_sub2.o test_sub3.o \
	-T test.x -Map test.map \
	--defsym label=0x100000 --defsym label2=0x1000 --defsym label3=0x200 \
	--defsym back=0x106 --defsym back2=0x10c --defsym=back3=0x110

test.elf:Makefile

test.o.objdump:test.o
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test.objdump:test.elf
	cr16-elf-objdump -d --dwarf=rawline,decodedline $< > $@

test.lof:test.log
