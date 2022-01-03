all:test.objdump test.o.objdump test.o.addr2line test.o.reloc test.lof

include ../Makefile.common

test.o.reloc:test.o
	ppc-elf-objdump -r $< > $@

test.o.addr2line:test.o
	ppc-elf-addr2line -a 0x0 -e $< > $@
	ppc-elf-addr2line -a 0x4 -e $< >> $@
	ppc-elf-addr2line -a 0x8 -e $< >> $@
	ppc-elf-addr2line -a 0xc -e $< >> $@

test.o.objdump:test.o
	ppc-elf-objdump -x -d -g $< > $@

test.elf:test.o test.x
	ppc-elf-ld -o test.elf test.o -T test.x -Map test.map

test.lof:test.log

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
	rm -f test.o.addr2line  test.o.reloc
