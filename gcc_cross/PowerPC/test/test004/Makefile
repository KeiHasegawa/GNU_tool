all:test004.objdump test004.lof

start.o:start.S
	ppc-elf-as -o $@ -g $<

#test004.s:test004.c
#	ppc-elf-gcc -o $@ -S $< -g

#test004.o:test004.s
#	ppc-elf-as -o $@ $<

test004.o:test004.c
	ppc-elf-gcc -o $@ $< -c -g

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/ppc-elf/lib/libc.a

test004.elf:start.o test004.o test004.x
	ppc-elf-ld -o $@ start.o test004.o $(LIBC) -T test004.x -Map test004.map

test004.objdump:test004.elf
	ppc-elf-objdump -x -d $< > $@

test004.log:test004.elf gdbcom
	wdog.exe -v ppc-elf-gdb -q -x gdbcom $< > $@

test004.lof:test004.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
