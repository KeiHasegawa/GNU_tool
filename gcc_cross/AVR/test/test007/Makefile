all:test007.objdump test007.lof

start.o:start.S
	avr-elf-as -o $@ -g $< -g


test007.s:test007.c
	avr-elf-gcc -o $@ -S $< -g

test007.o:test007.s
	avr-elf-as -o $@ $<

test007.elf:start.o test007.o test007.x
	avr-elf-ld -o $@ start.o test007.o -T test007.x -Map test007.map

test007.objdump:test007.elf
	avr-elf-objdump -x -d -g $< > $@

test007.log:test007.elf gdbcom
	wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@

test007.lof:test007.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~

