all:test007.objdump test007.lof

start.o:start.S
	ppc-elf-as -o $@ -g $<

#test007.s:test007.c
#	ppc-elf-gcc -o $@ -S $< -g

#test007.o:test007.s
#	ppc-elf-as -o $@ $<

test007.o:test007.c
	ppc-elf-gcc -o $@ $< -c -g

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/ppc-elf/lib/libc.a

test007.elf:start.o test007.o test007.x
	ppc-elf-ld -o $@ start.o test007.o $(LIBC) -T test007.x -Map test007.map

test007.objdump:test007.elf
	ppc-elf-objdump -x -d -g $< > $@

test007.log:test007.elf gdbcom
	wdog.exe -v ppc-elf-gdb -q -x gdbcom $< > $@

test007.lof:test007.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
