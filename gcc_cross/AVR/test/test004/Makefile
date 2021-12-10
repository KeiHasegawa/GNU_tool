all:test004.objdump test004.lof

start.o:start.S
	avr-elf-as -o $@ -g $<

#test004.s:test004.c
#	avr-elf-gcc -o $@ -S $<

#test004.o:test004.s
#	avr-elf-as -o $@ -g $<

test004.o:test004.c
	avr-elf-gcc -o $@ $< -c -g


LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/avr-elf/10.2.0/libgcc.a

#LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/avr-elf/10.2.0/double64/libgcc.a

#LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/avr-elf/10.2.0/long-double32/libgcc.a

test004.elf:start.o test004.o test004.x
	avr-elf-ld -o $@ start.o test004.o $(LIBGCC) -Map test004.map -T test004.x

test004.objdump:test004.elf
	avr-elf-objdump -x -d $< > $@

test004.log:test004.elf gdbcom
	wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@

test004.lof:test004.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
