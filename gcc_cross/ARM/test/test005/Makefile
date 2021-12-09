all:test005.objdump test005.lof

test005.o:test005.S
	arm-elf-as -o $@ -g $<

test005.elf:test005.o test005.x
	arm-elf-ld -o $@ test005.o -T test005.x -Map test005.map

test005.objdump:test005.elf
	arm-elf-objdump -x -d -g $< > $@

test005.log:test005.elf gdbcom
	wdog.exe -v arm-elf-gdb -q -x gdbcom $< > $@

test005.lof:test005.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.log *~

