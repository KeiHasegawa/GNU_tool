all:test005.objdump test005.lof

test005.o:test005.S
	avr-elf-as -o $@ -g $<

test005.elf:test005.o test005.x
	avr-elf-ld -o $@ test005.o -T test005.x -Map test005.map

test005.objdump:test005.elf
	avr-elf-objdump -x -d -g $< > $@

test005.log:test005.elf gdbcom
	wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@

test005.lof:test005.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.log *~

