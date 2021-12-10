all:test000.o.objdump test000.o.addr2line test000.objdump test000.addr2line test000.o.reloc test000.lof

test000.o:test000.S
	rl78-elf-as -o test000.o -g test000.S

test000.o.objdump:test000.o
	rl78-elf-objdump -x -d -g $< > $@

test000.o.reloc:test000.o
	rl78-elf-objdump -r $< > $@

test000.o.addr2line:test000.o
	rl78-elf-addr2line -a 0x0 -e $< > $@
	rl78-elf-addr2line -a 0x1 -e $< >> $@
	rl78-elf-addr2line -a 0x2 -e $< >> $@
	rl78-elf-addr2line -a 0x3 -e $< >> $@

test000.elf:test000.o test000.x
	rl78-elf-ld -o test000.elf test000.o -T test000.x -Map test000.map

test000.addr2line:test000.elf
	rl78-elf-addr2line -a 0x100 -e $< > $@
	rl78-elf-addr2line -a 0x101 -e $< >> $@
	rl78-elf-addr2line -a 0x102 -e $< >> $@
	rl78-elf-addr2line -a 0x103 -e $< >> $@

test000.objdump:test000.elf
	rl78-elf-objdump -x -d -g -r -s test000.elf > test000.objdump

test000.log:test000.elf gdbcom
	wdog.exe -v rl78-elf-gdb -q -x gdbcom $< >$@

test000.lof:test000.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.addr2line *.reloc *.log *~
