all:test005.objdump test005.lof

start.o:start.S
	ppc-elf-as -o $@ -g $<

test005.s:test005.c
	ppc-elf-gcc -o $@ -S $< -g

test005.o:test005.s
	ppc-elf-as -o $@ $<

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/ppc-elf/lib/libc.a

test005.elf:start.o test005.o test005.x
	ppc-elf-ld -o $@ start.o test005.o $(LIBC) -T test005.x -Map test005.map

test005.objdump:test005.elf
	ppc-elf-objdump -x -d -g $< > $@

test005.log:test005.elf gdbcom
	wdog.exe -v ppc-elf-gdb -q -x gdbcom $< > $@

test005.lof:test005.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
