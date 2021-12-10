all:test000.objdump test000.o.objdump test000.o.addr2line test000.o.reloc test000.lof

test000.o:test000.S
	ppc-elf-as -o test000.o -g test000.S

test000.o.objdump:test000.o
	ppc-elf-objdump -x -d -g $< > $@

test000.o.reloc:test000.o
	ppc-elf-objdump -r $< > $@

test000.o.addr2line:test000.o
	ppc-elf-addr2line -a 0x0 -e $< > $@
	ppc-elf-addr2line -a 0x4 -e $< >> $@
	ppc-elf-addr2line -a 0x8 -e $< >> $@
	ppc-elf-addr2line -a 0xc -e $< >> $@

test000.elf:test000.o test000.x
	ppc-elf-ld -o test000.elf test000.o -T test000.x -Map test000.map

test000.objdump:test000.elf
	ppc-elf-objdump -x -d -g $< > $@


test000.log:test000.elf gdbcom
	wdog.exe -v ppc-elf-gdb -q -x gdbcom $< > $@

test000.lof:test000.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.addr2line *.reloc *.log *~
