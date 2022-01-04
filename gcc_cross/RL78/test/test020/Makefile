all:test.o.objdump test.o.addr2line test.objdump test.addr2line test.o.reloc test.lof

include ../Makefile.common

test.o.objdump:test.o
	rl78-elf-objdump -x -d -g $< > $@

test.o.reloc:test.o
	rl78-elf-objdump -r $< > $@

test.o.addr2line:test.o
	rl78-elf-addr2line -a 0x0 -e $< > $@
	rl78-elf-addr2line -a 0x1 -e $< >> $@
	rl78-elf-addr2line -a 0x2 -e $< >> $@
	rl78-elf-addr2line -a 0x3 -e $< >> $@

test.elf:test.o test.x
	rl78-elf-ld -o test.elf test.o -T test.x -Map test.map

test.addr2line:test.elf
	rl78-elf-addr2line -a 0x100 -e $< > $@
	rl78-elf-addr2line -a 0x101 -e $< >> $@
	rl78-elf-addr2line -a 0x102 -e $< >> $@
	rl78-elf-addr2line -a 0x103 -e $< >> $@

test.lof:test.log

clean:
	rm -f *.o *.elf *.map *.objdump *.addr2line *.reloc *.log *~
