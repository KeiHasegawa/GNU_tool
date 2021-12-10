all:test008.objdump test008.lof

start.o:start.S
	avr-elf-as -o $@ -g $< -g


test008.s:test008.c
	avr-elf-gcc -o $@ -S $< -g

test008.o:test008.s
	avr-elf-as -o $@ $<

test008.elf:start.o test008.o test008.x
	avr-elf-ld -o $@ start.o test008.o -T test008.x -Map test008.map

test008.objdump:test008.elf
	avr-elf-objdump -x -d -g $< > $@

test008.log:test008.elf gdbcom
	wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@

test008.lof:test008.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~

