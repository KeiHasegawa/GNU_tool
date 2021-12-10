all:test009.objdump test009.lof

start.o:start.S
	avr-elf-as -o $@ -g $< -g

test009.s:test009.c
	avr-elf-gcc -o $@ -S $< -g

test009.o:test009.s
	avr-elf-as -o $@ $<

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/avr-elf/10.2.0/avr25/libgcc.a

test009.elf:start.o test009.o test009.x
	avr-elf-ld -o $@ start.o test009.o -T test009.x \
	-Map test009.map $(LIBGCC)

test009.objdump:test009.elf
	avr-elf-objdump -x -d -g $< > $@

test009.log:test009.elf gdbcom
	wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@

test009.lof:test009.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~

