all:test002.objdump test002.lof

start.o:start.S
	ppc-elf-as -o $@ -g $<

#test002.s:test002.c
#	ppc-elf-gcc -o $@ -S $<

#test002.o:test002.s
#	ppc-elf-as -o $@ -g $<

test002.o:test002.c
	ppc-elf-gcc -o $@ $< -c -g

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/ppc-elf/lib/libc.a

test002.elf:start.o test002.o test002.x
	ppc-elf-ld -o $@ start.o test002.o $(LIBC) -T test002.x -Map test002.map

test002.objdump:test002.elf
	ppc-elf-objdump -x -d $< > $@

test002.log:test002.elf gdbcom
	wdog.exe -v ppc-elf-gdb -q -x gdbcom $< > $@

test002.lof:test002.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
