all:test012.objdump test012.lof

start.o:start.S
	avr-elf-as -o $@ -g $< -g


test012.s:test012.c
	avr-elf-gcc -o $@ -S $< -g

test012.o:test012.s
	avr-elf-as -o $@ $<

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/avr-elf/10.2.0/avr25/libgcc.a

test012.elf:start.o test012.o test012.x
	avr-elf-ld -o $@ start.o test012.o -T test012.x \
	-Map test012.map $(LIBGCC)

test012.objdump:test012.elf
	avr-elf-objdump -x -d -g $< > $@

test012.log:test012.elf gdbcom
	wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@

test012.lof:test012.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~

