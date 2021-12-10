all:test010.objdump test010.lof

start.o:start.S
	avr-elf-as -o $@ -g $< -g


test010.s:test010.c
	avr-elf-gcc -o $@ -S $< -g

test010.o:test010.s
	avr-elf-as -o $@ $<

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/avr-elf/10.2.0/avr25/libgcc.a

test010.elf:start.o test010.o test010.x
	avr-elf-ld -o $@ start.o test010.o -T test010.x \
	-Map test010.map $(LIBGCC)

test010.objdump:test010.elf
	avr-elf-objdump -x -d -g $< > $@

test010.log:test010.elf gdbcom
	wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@

test010.lof:test010.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~

